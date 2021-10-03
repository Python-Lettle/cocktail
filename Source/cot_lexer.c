/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

#include "cot_lexer.h"

// 扫描并获取token链表
void cot_token_scan(FILE * fpin, int showToken)
{
    if(__DEBUG_MODE__){
        printf("Scanner start!!!\n");
    }

    /**
     * 扫描器所需
     */
    char ch = ' ';      // 取一个字符
    char str[VAR_NAME_MAX_LEN] = "";     // 用str连接字符串
    unsigned int str_len = 0;
    // int counter = 0;    // 记录token数
    bool noneed = false; // 下一循环是否需要获取
//    cot_token_stream_init();
    cot_token *token = (cot_token *) malloc (sizeof (cot_token));
    cot_token_head = token;

    /**
     * Token属性
     */
//    cot_token token = { 0 };
    short char_count = 0; // 当前字符位置
    short line = 1;       // 当前行号

    bool isFloat = false; // 是否为小数 0否 1是

    while (ch != EOF) {
        if (!noneed) {
            ch = fgetc(fpin); char_count++;
            if(ch==EOF){break;}
        } else noneed = 0;
        // 新的token, 清空原有token记录
        for(int i=0;i<str_len;i++)
            str[i] = '\0';
        str_len = 0;

        //判断过滤符
        if(ch=='\n'){
            line++;char_count=0;
            continue;} //行数增加

        // 过滤符号跳过
        if(IsFilter(ch)) continue;

        // 判断关键字或变量名
        else if(IsLetter(ch)) {
            token->ch = char_count;  // 记录当前token位置
            token->line = line;
            // 继续获取token
            while (IsLetter(ch) || IsDigit(ch) || (ch=='_') || (ch=='.')) {
                // 加入str缓存
                str[str_len++] = ch;

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
            } noneed = true;
//            token->value.string_value = str;
            strcpy(token->value.string_value, str);
            // 判断是否为关键字
            if(IsKeyword(str)) {
                if (strcmp(str,"import") == 0)
                    token->value.type = IMPORT;
                else if (strcmp(str,"function") == 0)
                    token->value.type = FUNCTION;
                else if (strcmp(str,"return") == 0)
                    token->value.type = RETURN;
                else if (strcmp(str,"if") == 0)
                    token->value.type = IF;
                else if (strcmp(str,"else") == 0)
                    token->value.type = ELSE;
                else if (strcmp(str,"while") == 0)
                    token->value.type = WHILE;
                else if (strcmp(str,"for") == 0)
                    token->value.type = FOR;
                else if (strcmp(str,"do") == 0)
                    token->value.type = DO;
                else if (strcmp(str,"continue") == 0)
                    token->value.type = CONTINUE;
                else if (strcmp(str,"break") == 0)
                    token->value.type = BREAK;
                else if (strcmp(str,"class") == 0)
                    token->value.type = CLASS;
                else if (strcmp(str,"True") == 0)
                    token->value.type = TRUE;
                else if (strcmp(str,"False") == 0)
                    token->value.type = FALSE;
                else if (strcmp(str,"int") == 0)
                    token->value.type = INT;
                else if (strcmp(str,"double") == 0)
                    token->value.type = DOUBLE;
                else if (strcmp(str,"string") == 0)
                    token->value.type = STRING;
                else if (strcmp(str,"void") == 0)
                    token->value.type = VOID;
            }
            // 是标识符
            else {
                token->value.type = IDENTIFIER;
            }
        }

        // 判断是否为"包裹的字符串常量
        else if(ch=='"') {
            // 记录当前token位置
            token->ch = char_count;
            token->line = line;

            ch = fgetc(fpin); char_count++;

            while (ch != '"') {
                // 加入str缓存
                str[str_len++] = ch;

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
            }
            strcpy(token->value.string_value, str);
            token->value.type = STRING_LITERAL;
        }

        // 判断是否为数字常量
        else if(IsDigit(ch)) {
            // 记录当前token位置
            token->ch = char_count;
            token->line = line;
            str[str_len++] = ch;

            while (IsDigit(ch) || ch=='.') {
                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
                while (IsFilter(ch)){
                    //判断换行符
                    if(ch=='\n'){
                        line++;char_count=0;
                        continue;} //行数增加
                    ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
                } // 过滤符号跳过
                str[str_len++] = ch;
                if (ch=='.') {
                    if (isFloat == 0) {
                        isFloat = 1;
                        continue;
                    } else {
                        printf("Token scanner found an error: %s\n",str);
                        exit(1);
                    }
                }
            } noneed = 1;

            // 判断是小数还是整数
            if (isFloat) {
                // 是小数
                token->value.float_value = atof(str);
                token->value.type = FLOAT_LITERAL;
                isFloat = true;
            } else {
                token->value.int_value = atoi(str);
                token->value.type = INTEGER_LITERAL;
            }
        }

        // 判断 分隔符
        else if(IsSeparater(ch)) {
            token->ch = char_count; token->line = line;
            switch (ch) {
                case '(':
                    token->value.type = LP;
                    break;
                case ')':
                    token->value.type = RP;
                    break;
                case '{':
                    token->value.type = LC;
                    break;
                case '}':
                    token->value.type = RC;
                    break;
                case '[':
                    token->value.type = LB;
                    break;
                case ']':
                    token->value.type = RB;
                    break;
                case ';':
                    token->value.type = SEMICOLON;
                    break;
                case ',':
                    token->value.type = COMMA;
                    break;
                default:
                    break;
            }
            strcpy(token->value.string_value,""); // 清空一下string_value
            token->value.string_value[0] = ch;
            token->value.string_value[1] = '\0';
        }
        // 判断为 操作符 或 分隔符
        else if(IsOperator(ch)) {
            // 记录当前token位置
            token->ch = char_count;
            token->line = line;

            str[str_len++] = ch;
            ch = fgetc(fpin); char_count++;
            // 双符形式
            if(IsOperator(ch)) {
                str[str_len++] = ch;

                // 注释判断
                if (strcmp(str,"//") == 0) {
                    while (ch != '\n')
                        ch = fgetc(fpin);
                    line++;
                    continue;
                }else if (strcmp(str,"/*") == 0) {
                    bool isFinish = false, nonext = false;
                    while(!isFinish) {
                        if (!nonext)
                            ch = fgetc(fpin);
                        if (ch=='*') {
                            ch = fgetc(fpin);
                            if(ch=='/') isFinish = true;
                            else if(ch=='*') nonext = true;
                        }
                        if (ch=='\n') line++;
                    }
                    continue;
                }

                else if (strcmp(str,"&&") != 0) { token->value.type = LOGICAL_AND; strcpy(token->value.string_value, str);}
                else if (strcmp(str,"||") == 0) { token->value.type = LOGICAL_OR; strcpy(token->value.string_value, str);}
                else if (strcmp(str,"==") == 0) { token->value.type = EQ; strcpy(token->value.string_value, str);}
                else if (strcmp(str,"!=") == 0) { token->value.type = NE; strcpy(token->value.string_value, str);}
                else if (strcmp(str,">=") == 0) { token->value.type = GE; strcpy(token->value.string_value, str);}
                else if (strcmp(str,"<=") == 0) { token->value.type = LE; strcpy(token->value.string_value, str);}
                continue;
            }
            // 单符形式
            switch (str[0]) {
                case '=':
                    token->value.type = ASSIGN;
                    break;
                case '!':
                    token->value.type = INVERT;
                    break;
                case '>':
                    token->value.type = GT;
                    break;
                case '<':
                    token->value.type = LT;
                    break;
                case '+':
                    token->value.type = ADD;
                    break;
                case '-':
                    token->value.type = SUB;
                    break;
                case '*':
                    token->value.type = MUL;
                    break;
                case '/':
                    token->value.type = DIV;
                    break;
                case '%':
                    token->value.type = MOD;
                    break;
                case '.':
                    token->value.type = DOT;
                    break;
                case '#':
                    token->value.type = SHARP;
                    break;
            }
            noneed = true;
            strcpy(token->value.string_value,""); // 清空一下string_value
            token->value.string_value[0] = str[0];
            token->value.string_value[1] = '\0';
        }

        // 未识别出类型, 报错
        else
            printf("Wrong token in line %d: %s\n", line, str);

        if(showToken)
            cot_token_show(token);

        token->next = (cot_token *) malloc (sizeof(cot_token));
        token = token->next;

    }
}

void cot_token_show (cot_token *token1)
{
    cot_token *token = token1;
    while (token) {
        switch (token->value.type) {
            case STRING_LITERAL:
                printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"STRING_LITERAL");
                break;
            case INTEGER_LITERAL:
                printf("(%4d:%4d):\t%20d\t%20s\n",token->line,token->ch,token->value.int_value,"INTEGER_LITERAL");
                break;
            case FLOAT_LITERAL:
                printf("(%4d:%4d):\t%20f\t%20s\n",token->line,token->ch,token->value.float_value,"FLOAT_LITERAL");
                break;
            case STRING:
            case INT:
            case DOUBLE:
            case IDENTIFIER:
                printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"IDENTIFIER");
                break;
            case FUNCTION:
                printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"FUNCTION");
                break;
            case RETURN:
                printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"RETURN");
                break;
            case IMPORT:
                printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"IMPORT");
                break;
            case WHILE:
                printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"WHILE");
                break;
            default:
                if (token->value.type < 24) {
                    printf("(%4d:%4d):\t%20s\t%20s\n",token->line,token->ch,token->value.string_value,"MARK");
                    break;
                }
                printf("(%4d:%4d):\t%20s\t%20d\n",token->line,token->ch,token->value.string_value,token->value.type);
        }
        token = token->next;
    }
}