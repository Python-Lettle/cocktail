/*
 * Created by Lettle on 2021/9/3.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COT_PARSER_H
#define COCKTAIL_COT_PARSER_H

#include "cot_lexer.h"

// 一个语法树节点
typedef struct Node_tag {
    // 一个何种类型的语法
    int type;
    cot_token token;
} Node;


// 利用token流分析语法
void parse();

#endif //COCKTAIL_COT_PARSER_H
