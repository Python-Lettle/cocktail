/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COT_UTIL_H
#define COCKTAIL_COT_UTIL_H

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif // MIN

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif // MAX

#include "cot_type.h"
typedef struct {
    // 代行号
    int line;
    // 词位置
    int ch;
    // token的值
    cot_value value;
} cot_token;

enum {
    LP,
    RP,
    LC,
    RC,
    LB,
    RB,
    LOGICAL_AND,
    LOGICAL_OR,
    ASSIGN,
    EQ,
    INVERT,
    NE,
    GT,
    GE,
    LT,
    LE,
    ADD,
    SUB,
    MUL,
    DIV,
    MOD,
    SEMICOLON,
    COMMA,
    DOT,
    IMPORT,
    FUNCTION,
    RETURN,
    IF,
    ELSE,
    WHILE,
    FOR,
    DO,
    CONTINUE,
    BREAK,
    CLASS,
    TRUE,
    FALSE,
    INT,
    DOUBLE,
    STRING,
    VOID,
    IDENTIFIER,
    INTEGER_LITERAL,
    FLOAT_LITERAL,
    STRING_LITERAL,
};

enum {
    COT_NULL_VALUE,
    COT_BOOLEAN_VALUE,
    COT_INT_VALUE,
    COT_DOUBLE_VALUE,
    COT_STRING_VALUE,
    COT_INSTANCE_VALUE,
    COT_FUNCTION_VALUE,
};

/**
 * 词法解析器相关
 */

#define keywordSum 11


int IsKeyword(char * word);
int IsSeparater(char ch);
int IsOperator(char ch);
int IsFilter(char ch);
int IsUpLetter(char ch);
int IsLowLetter(char ch);
int IsLetter(char ch);
int IsDigit(char ch);

#endif //COCKTAIL_COT_UTIL_H
