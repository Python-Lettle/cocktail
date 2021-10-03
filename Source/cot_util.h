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
#include "cot_type.h"

#ifndef MIN
#define MIN(a, b) (a < b ? a : b)
#endif // MIN

#ifndef MAX
#define MAX(a, b) (a > b ? a : b)
#endif // MAX

#define bool char
#define true 1
#define false 0

/**********************************************************************
 * cot_token
 **********************************************************************/
typedef struct cot_token *cot_token_p;
typedef struct {
    // 代行号
    short line;
    // 词位置
    short ch;
    // token的值
    cot_value value;
    // 链表
    cot_token_p next;
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
    SHARP,          // #
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
#define opratorSum 9
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

/**********************************************************************
 * cot_parser
 **********************************************************************/
// TODO: 单目运算符没有制作：按位取反~ 自增自减 负号 类型转换 指针 取地址 长度运算符
//       双目运算符没有制作：左移右移 按位与 按位异或^ 按位或| 求余%

// 变量名最长字符数
#define VAR_NAME_MAX_LEN 50
// 变量体占字节大小
#define VAR_LEN sizeof(cot_var)

// 一个Expression代表的类型
enum {
    COT_NULL_EXP,                   // 空值
    COT_BOOLEAN_EXP,                // 布尔值
    COT_INT_EXP,                    // 整数
    COT_FLOAT_EXP,                  // 双精度小数
    COT_STRING_EXP,                 // 字符串
    COT_INSTANCE_EXP,               // 实例
    COT_FUNCTION_EXP,               // 函数
    // unary expression
    COT_NOT_EXP,                    // ! 非

    // binary expression
    COT_ASSIGN_EXP,                 // = 赋值
    COT_ADD_EXP,                    // + 加法表达式
    COT_SUB_EXP,                    // - 减法表达式
    COT_MUL_EXP,                    // * 乘法表达式
    COT_DIV_EXP,                    // / 除法表达式
    COT_LOGICAL_AND_EXP,            // && 逻辑和
    COT_LOGICAL_OR_EXP,             // || 逻辑与

    COT_FUNCTION_CALL_EXP,          // function() 函数调用

};

// 语法节点类型
enum {
    global_block = 1,
    statement_list,
    statement,
    function_definition_statement,
    if_statement,
    for_statement,
    expression_opt,
    expression,
    define_expression_list,
    define_expression,
    assignment_expression,
    logical_or_expression,
    equality_expression,
    relational_expression,
    additive_expression,
    unary_expression,
    primary_expression,
    argument_list,
    function_definition,
    parameter_list,
    block
};

// 变量体 varname(char) : value(cot_value)
typedef struct
{
    char varname[VAR_NAME_MAX_LEN];
    cot_value value;
} cot_var;

// 语法节点
typedef struct
{
    unsigned short type;
    cot_value value;
    union {
        cot_token *token_list;
        struct cot_node *node_list;
    };
    unsigned short token_list_length;
} cot_node;

typedef struct
{
    cot_node statement_list;        // 语句链表
    unsigned short var_count;       // 变量数量
    cot_var *vars;              // 变量数组
} cot_global_block;

#endif //COCKTAIL_COT_UTIL_H
