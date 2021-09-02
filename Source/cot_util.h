
/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COT_UTIL_H
#define COCKTAIL_COT_UTIL_H

#include <stdio.h>
#include <string.h>

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

// 值的内容
enum {
    LP,             // (
    RP,             // )
    LC,             // {
    RC,             // }
    LB,             // [
    RB,             // ]
    LOGICAL_AND,    // &&
    LOGICAL_OR,     // ||
    ASSIGN,         // =
    EQ,             // ==
    INVERT,         // !
    NE,             // !=
    GT,             // >
    GE,             // >=
    LT,             // <
    LE,             // <=
    ADD,            // +
    SUB,            // -
    MUL,            // *
    DIV,            // /
    MOD,            // %
    SEMICOLON,      // ;
    COMMA,          // ,
    DOT,            // .
    IMPORT,         // import
    FUNCTION,       // function
    RETURN,         // return
    IF,             // if
    ELSE,           // else
    WHILE,          // while
    FOR,            // for
    DO,             // do
    CONTINUE,       // continue
    BREAK,          // break
    CLASS,          // class
    TRUE,           // True
    FALSE,          // False
    INT,            // 整型
    DOUBLE,         // 双精度小数型
    STRING,         // 字符串类型
    VOID,           // 无类型
    IDENTIFIER,     // 名称
    INTEGER_LITERAL,    // 整数常量
    FLOAT_LITERAL,      // 浮点数常量
    STRING_LITERAL,     // 字符串常量
};

// 一个值的类型
enum {
    COT_NULL_VALUE,         // 空值
    COT_BOOLEAN_VALUE,      // 布尔值
    COT_INT_VALUE,          // 整数
    COT_DOUBLE_VALUE,       // 双精度小数
    COT_STRING_VALUE,       // 字符串
    COT_INSTANCE_VALUE,     // 实例
    COT_FUNCTION_VALUE,     // 函数
};

/**
 * 词法解析器相关
 */

// 关键字总数
#define keywordSum 12
// 数据类型总数
#define vartypeSum 5
// 分隔符总数
#define separaterSum 8
// 操作符总数
#define opratorSum 8
// 过滤符总数
#define filterSum 4


int IsKeyword(char * word);
int IsSeparater(char ch);
int IsOperator(char ch);
int IsFilter(char ch);
int IsUpLetter(char ch);
int IsLowLetter(char ch);
int IsLetter(char ch);
int IsDigit(char ch);

#endif //COCKTAIL_COT_UTIL_H
