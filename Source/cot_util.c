/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

#include "cot_util.h"
#include <string.h>

// 关键字
const char * KEYWORD_LIST[keywordSum]={
        "import",
        "if","else","void","return",
        "while","for","do",
        "int","string","double"};

// 数据类型
const char * VARTYPE_LIST[5]={
        "int","string","double","void"
};

// 分隔符
const char SEPARATER_LIST[8]={';',',','{','}','[',']','(',')'};
// 运算符
const char OPERATOR_LIST[8]={'+','-','*','/','>','<','=','!'};
// 过滤符
const char FILTER_LIST[4]={' ','\t','\r','\n'};

/** 判断是否为关键字 **/
int IsKeyword(char * word){
    for(int i=0;i<15;i++){
        if(strcmp(KEYWORD_LIST[i],word)){
            return 1;
        }
    }
    return 0;
}
/** 判断是否为分隔符 **/
int IsSeparater(char ch){
    for(int i=0;i<8;i++){
        if(SEPARATER_LIST[i]==ch){
            return 1;
        }
    }
    return 0;
}

/** 判断是否为运算符 **/
int IsOperator(char ch){
    for(int i=0;i<8;i++){
        if(OPERATOR_LIST[i]==ch){
            return 1;
        }
    }
    return 0;
}
/** 判断是否为过滤符 **/
int IsFilter(char ch){
    for(int i=0;i<4;i++){
        if(FILTER_LIST[i]==ch){
            return 1;
        }
    }
    return 0;
}
/** 判断是否为大写字母 **/
int IsUpLetter(char ch) {
    if(ch>='A' && ch<='Z') return 1;
    return 0;
}
/** 判断是否为小写字母 **/
int IsLowLetter(char ch) {
    if(ch>='a' && ch<='z') return 1;
    return 0;
}

/** 判断是否为字母 **/
int IsLetter(char ch) {
    if(IsLowLetter(ch) || IsUpLetter(ch)) return 1;
    return 0;
}
/** 判断是否为数字 **/
int IsDigit(char ch) {
    if(ch>='0' && ch<='9') return 1;
    return 0;
}


