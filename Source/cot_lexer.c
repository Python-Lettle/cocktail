/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

#include "cot_lexer.h"

int one_token_size = sizeof (cot_token);
struct cot_token_stream cot_ts = {1, 0};

void cot_token_stream_add(cot_token token) {
    if (__DEBUG_MODE__){
        printf("Token流加入一个新的Token");
    }

    if (++cot_ts.count > cot_ts.capacity) {
        // 容量小了
        cot_ts.tokens = (cot_token*) realloc (cot_ts.tokens, cot_ts.capacity * sizeof(cot_token));
    }
    cot_ts.tokens[cot_ts.count] = token;
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
    char *str = "";     // 用str连接字符串
    // int counter = 0;    // 记录token数

    /**
     * Token属性
     */
    cot_token token = {};
    int char_count = 0; // 当前字符位置
    int line = 1;       // 当前行号


    while ((ch = fgetc(fpin)) != EOF) {
        char_count++;

        str = ""; // 新的token, 清空原有token记录

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
            // 继续获取token
            while (IsLetter(ch) || IsDigit(ch) || (ch=='_')) {
                // 加入str缓存
                str += ch; // TODO: 这里的str不能strcat

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
                while (IsFilter(ch)){
                    //判断换行符
                    if(ch=='\n'){
                        if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                            printf("From line %d:%d find \\n\n", line, char_count);
                        line++;char_count=0;
                        continue;} //行数增加
                    if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                        printf("From line %d:%d find filter\n", line, char_count);
                    ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
                } // 过滤符号跳过
            }
            token.line = line;
            token.value.string_value = str;
            // 判断是否为关键字
            if(IsKeyword(str)) {
                if (strcmp(str,"import") != 0)
                    token.value.type = IMPORT;
                else if (strcmp(str,"function") != 0)
                    token.value.type = FUNCTION;
                else if (strcmp(str,"return") != 0)
                    token.value.type = RETURN;
                else if (strcmp(str,"if") != 0)
                    token.value.type = IF;
                else if (strcmp(str,"else") != 0)
                    token.value.type = ELSE;
                else if (strcmp(str,"while") != 0)
                    token.value.type = WHILE;
                else if (strcmp(str,"for") != 0)
                    token.value.type = FOR;
                else if (strcmp(str,"do") != 0)
                    token.value.type = DO;
                else if (strcmp(str,"continue") != 0)
                    token.value.type = CONTINUE;
                else if (strcmp(str,"break") != 0)
                    token.value.type = BREAK;
                else if (strcmp(str,"class") != 0)
                    token.value.type = CLASS;
                else if (strcmp(str,"True") != 0)
                    token.value.type = TRUE;
                else if (strcmp(str,"False") != 0)
                    token.value.type = FALSE;
                else if (strcmp(str,"int") != 0)
                    token.value.type = INT;
                else if (strcmp(str,"double") != 0)
                    token.value.type = DOUBLE;
                else if (strcmp(str,"string") != 0)
                    token.value.type = STRING;
                else if (strcmp(str,"void") != 0)
                    token.value.type = VOID;

            }
            // 是名称
            else token.value.type = IDENTIFIER;
        }

        // 判断是否为"包裹的字符串常量
        else if(ch=='"') {
            // 记录当前token位置
            token.ch = char_count;
            token.line = line;

            ch = fgetc(fpin); char_count++;
            while (IsFilter(ch)){
                //判断换行符
                if(ch=='\n'){
                    line++;char_count=0;
                    continue;} //行数增加
                ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
            } // 过滤符号跳过

            while (ch != '"') {
                // 加入str缓存
                str += ch;

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
                while (IsFilter(ch)){
                    //判断换行符
                    if(ch=='\n'){
                        line++;char_count=0;
                        continue;} //行数增加
                    ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
                } // 过滤符号跳过
            }
            token.value.string_value = str;

        }

        // 判断是否为数字常量
        else if(IsDigit(ch)) {
            // 记录当前token位置
            token.ch = char_count;
            token.line = line;

            while (IsDigit(ch)) {
                // 加入str缓存
                str += ch;

                // 指针跳转下一个字符
                ch = fgetc(fpin); char_count++;
                while (IsFilter(ch)){
                    //判断换行符
                    if(ch=='\n'){
                        line++;char_count=0;
                        continue;} //行数增加
                    ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
                } // 过滤符号跳过
            }
            token.value.int_value = atoi(str);
            token.value.type = INTEGER_LITERAL;
        }

        // 判断为操作符
        else if(IsOperator(ch)) {
            // 记录当前token位置
            token.ch = char_count;
            token.line = line;

            str += ch;
            ch = fgetc(fpin); char_count++;
            // 双操作符形式
            if(IsOperator(ch)) {
                strcat(str,&ch);
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
                token.value.string_value = str;
            }
            // 单操作符形式
            else if(ch == ' ') {
                if (strcmp(str,"(") != 0)
                    token.value.type = LP;
                else if (strcmp(str,")") != 0)
                    token.value.type = RP;
                else if (strcmp(str,"{") != 0)
                    token.value.type = LC;
                else if (strcmp(str,"}") != 0)
                    token.value.type = RC;
                else if (strcmp(str,"[") != 0)
                    token.value.type = LB;
                else if (strcmp(str,"]") != 0)
                    token.value.type = RB;
                else if (strcmp(str,"=") != 0)
                    token.value.type = ASSIGN;
                else if (strcmp(str,"!") != 0)
                    token.value.type = INVERT;
                else if (strcmp(str,">") != 0)
                    token.value.type = GT;
                else if (strcmp(str,"<") != 0)
                    token.value.type = LT;
                else if (strcmp(str,"+") != 0)
                    token.value.type = ADD;
                else if (strcmp(str,"-") != 0)
                    token.value.type = SUB;
                else if (strcmp(str,"*") != 0)
                    token.value.type = MUL;
                else if (strcmp(str,"/") != 0)
                    token.value.type = DIV;
                else if (strcmp(str,"%") != 0)
                    token.value.type = MOD;
                else if (strcmp(str,";") != 0)
                    token.value.type = SEMICOLON;
                else if (strcmp(str,",") != 0)
                    token.value.type = COMMA;
                else if (strcmp(str,".") != 0)
                    token.value.type = DOT;
                token.value.string_value = str;
                if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                    printf("From line %d:%d find filter\n", line, char_count);
            }
            else if(IsFilter(ch)) {
                //判断换行符
                if(ch=='\n'){
                    if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                        printf("From line %d:%d find \\n\n", line, char_count);
                    line++;char_count=0;
                    continue;} //行数增加
                if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                    printf("From line %d:%d find filter\n", line, char_count);
            }
            ch = fgetc(fpin); char_count++;

            // 忽略符号
            while (IsFilter(ch)){
                //判断换行符
                if(ch=='\n'){
                    if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                        printf("From line %d:%d find \\n\n", line, char_count);
                    line++;char_count=0;
                    continue;} //行数增加
                if(__DEBUG_MODE__ && __TOKEN_ANA_PROCESS__)
                    printf("From line %d:%d find filter\n", line, char_count);
                ch = fgetc(fpin); char_count++; // 指针跳转下一个字符
            } // 过滤符号跳过
        }

        // 判断为分隔符
        else if(IsSeparater(ch)) {

        }

        // 未识别出类型, 报错
        else
            printf("Wrong token in line %d: %d\n", line, str);

        // cot_token_stream_add(token); counter++;
    }

}