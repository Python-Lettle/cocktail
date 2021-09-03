/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

#include "cot_lexer.h"

int one_token_size = sizeof (cot_token);
cot_token_stream cot_ts;

void cot_token_stream_init () {
    cot_ts.count = 0;
    cot_ts.capacity = 5 * sizeof(cot_token);
    cot_ts.tokens = (cot_token*) malloc (cot_ts.capacity);
    if (!cot_ts.tokens){
        printf("Failed to init token stream!\n");
        exit(1);
    }
}

void cot_token_stream_add(cot_token token) {
    if (__DEBUG_MODE__){
        printf("Token流加入一个新的");
        cot_token_show(token);
    }

    if ( cot_ts.count == (cot_ts.capacity / sizeof(cot_token)) ) {
        // 容量小了
        cot_ts.capacity *= 2;
        cot_ts.tokens = (cot_token*) realloc (cot_ts.tokens, cot_ts.capacity);
        if (__DEBUG_MODE__) {
            printf("Token_stream.capacity doubled, now: %d\n", cot_ts.capacity);
        }
    }
    cot_token temp;
    memcpy(&temp,&token,sizeof (token));
    cot_ts.tokens[cot_ts.count++] = temp;
}

cot_token cot_token_stream_get (int index) {
    if ( index>=0 && index<cot_ts.count) {
        return cot_ts.tokens[index];
    }
    printf("Wrone index to get token from stream.\n");
    exit(1);
}

// 扫描并获取token流
void cot_token_scan(FILE * fpin)
{
    if(__DEBUG_MODE__){
        printf("Scanner start!!!\n");
    }

    /**
     * 扫描器所需
     */
    char ch = ' ';      // 取一个字符
    char str[100] = "";     // 用str连接字符串
    int str_len = 0;
    // int counter = 0;    // 记录token数
    int noneed = 0; // 下一循环是否需要获取
    cot_token_stream_init(cot_ts);

    /**
     * Token属性
     */
    cot_token token = {};
    int char_count = 0; // 当前字符位置
    int line = 1;       // 当前行号


    while (ch != EOF) {
        if (!noneed) {
            ch = fgetc(fpin); char_count++;
            if(ch==EOF){break;}
        } else noneed = 0;
        // 新的token, 清空原有token记录
        for(int i=0;i<str_len;i++)
            str[i] = '\0';
        str_len = 0;
        token.value.type = 0; token.line = 0;token.ch=0;

        //判断过滤符
        if(ch=='\n'){
            if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                printf("From line %d:%d find \\n\n", line, char_count);
            line++;char_count=0;
            continue;} //行数增加

        // 过滤符号跳过
        if(IsFilter(ch)) {
            if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                printf("From line %d:%d find filter\n", line, char_count);
            continue;}

        // 判断关键字或变量名
        else if(IsLetter(ch)) {
            token.ch = char_count;  // 记录当前token位置
            token.line = line;
            // 继续获取token
            while (IsLetter(ch) || IsDigit(ch) || (ch=='_')) {
                // 加入str缓存
                str[str_len++] = ch;

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
            } noneed = 1;
            token.value.string_value = str;
            // 判断是否为关键字
            if(IsKeyword(str)) {
                if (strcmp(str,"import") == 0)
                    token.value.type = IMPORT;
                else if (strcmp(str,"function") == 0)
                    token.value.type = FUNCTION;
                else if (strcmp(str,"return") == 0)
                    token.value.type = RETURN;
                else if (strcmp(str,"if") == 0)
                    token.value.type = IF;
                else if (strcmp(str,"else") == 0)
                    token.value.type = ELSE;
                else if (strcmp(str,"while") == 0)
                    token.value.type = WHILE;
                else if (strcmp(str,"for") == 0)
                    token.value.type = FOR;
                else if (strcmp(str,"do") == 0)
                    token.value.type = DO;
                else if (strcmp(str,"continue") == 0)
                    token.value.type = CONTINUE;
                else if (strcmp(str,"break") == 0)
                    token.value.type = BREAK;
                else if (strcmp(str,"class") == 0)
                    token.value.type = CLASS;
                else if (strcmp(str,"True") == 0)
                    token.value.type = TRUE;
                else if (strcmp(str,"False") == 0)
                    token.value.type = FALSE;
                else if (strcmp(str,"int") == 0)
                    token.value.type = INT;
                else if (strcmp(str,"double") == 0)
                    token.value.type = DOUBLE;
                else if (strcmp(str,"string") == 0)
                    token.value.type = STRING;
                else if (strcmp(str,"void") == 0)
                    token.value.type = VOID;
            }
            // 是标识符
            else {
                token.value.type = IDENTIFIER;
            }
        }

        // 判断是否为"包裹的字符串常量
        else if(ch=='"') {
            // 记录当前token位置
            token.ch = char_count;
            token.line = line;

            ch = fgetc(fpin); char_count++;

            while (ch != '"') {
                // 加入str缓存
                str[str_len++] = ch;

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
            } noneed = 1;
            token.value.string_value = str;
        }

        // 判断是否为数字常量
        else if(IsDigit(ch)) {
            // 记录当前token位置
            token.ch = char_count;
            token.line = line;
            str[str_len++] = ch;

            while (IsDigit(ch)) {
                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
                while (IsFilter(ch)){
                    //判断换行符
                    if(ch=='\n'){
                        line++;char_count=0;
                        continue;} //行数增加
                    ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
                } // 过滤符号跳过
            } noneed = 1;
            token.value.int_value = atoi(str);
            token.value.type = INTEGER_LITERAL;
        }

        // 判断为 操作符 或 分隔符
        else if(IsOperator(ch) || IsSeparater(ch)) {
            // 记录当前token位置
            token.ch = char_count;
            token.line = line;

            str[str_len++] = ch;
            ch = fgetc(fpin); char_count++;
            // 双符形式
            if(IsOperator(ch)) {
                str[str_len++] = ch;
                if (strcmp(str,"&&") != 0)
                    token.value.type = LOGICAL_AND;
                else if (strcmp(str,"||") != 0)
                    token.value.type = LOGICAL_OR;
                else if (strcmp(str,"==") != 0)
                    token.value.type = EQ;
                else if (strcmp(str,"!=") != 0)
                    token.value.type = NE;
                else if (strcmp(str,">=") != 0)
                    token.value.type = GE;
                else if (strcmp(str,"<=") != 0)
                    token.value.type = LE;
            }
            // 单符形式
            else {
                switch (str[0]) {
                    case '(':
                        token.value.type = LP;
                        break;
                    case ')':
                        token.value.type = RP;
                        break;
                    case '{':
                        token.value.type = LC;
                        break;
                    case '}':
                        token.value.type = RC;
                        break;
                    case '[':
                        token.value.type = LB;
                        break;
                    case ']':
                        token.value.type = RB;
                        break;
                    case '=':
                        token.value.type = ASSIGN;
                        break;
                    case '!':
                        token.value.type = INVERT;
                        break;
                    case '>':
                        token.value.type = GT;
                        break;
                    case '<':
                        token.value.type = LT;
                        break;
                    case '+':
                        token.value.type = ADD;
                        break;
                    case '-':
                        token.value.type = SUB;
                        break;
                    case '*':
                        token.value.type = MUL;
                        break;
                    case '/':
                        token.value.type = DIV;
                        break;
                    case '%':
                        token.value.type = MOD;
                        break;
                    case ';':
                        token.value.type = SEMICOLON;
                        break;
                    case ',':
                        token.value.type = COMMA;
                        break;
                    case '.':
                        token.value.type = DOT;
                        break;
                }
            }
            noneed = 1;
            token.value.string_value = str;
        }

        // 未识别出类型, 报错
        else
            printf("Wrong token in line %d: %s\n", line, str);

        cot_token_stream_add(token);
    }
    // TODO: 这里的token.value消失了
    printf("-----------------------------------------------\n");
    for (int i=0; i < cot_ts.count; i++){
        cot_token_show(cot_token_stream_get(i));
    }
}

void cot_token_show (cot_token token)
{
    switch (token.value.type) {
        case STRING_LITERAL:
            printf("Token(%d:%d):  %s    %s\n",token.line,token.ch,token.value.string_value,"STRING_LITERAL");
            break;
        case INTEGER_LITERAL:
            printf("Token(%d:%d):  %d    %s\n",token.line,token.ch,token.value.int_value,"INTEGER_LITERAL");
            break;
        case FLOAT_LITERAL:
            printf("Token(%d:%d):  %f    %s\n",token.line,token.ch,token.value.float_value,"FLOAT_LITERAL");
            break;
        case STRING:
        case INT:
        case DOUBLE:
        case IDENTIFIER:
            printf("Token(%d:%d):  %s    %s\n",token.line,token.ch,token.value.string_value,"IDENTIFIER");
            break;
        case FUNCTION:
            printf("Token(%d:%d):  %s    %s\n",token.line,token.ch,token.value.string_value,"FUNCTION");
            break;
        case RETURN:
            printf("Token(%d:%d):  %s    %s\n",token.line,token.ch,token.value.string_value,"RETURN");
            break;
        default:
            printf("Token(%d:%d):  %s    %d\n",token.line,token.ch,token.value.string_value,token.value.type);
    }

}