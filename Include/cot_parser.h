/*
 * Created by Lettle on 2021/9/3.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */

/**
 * global_block:
 *              | statement statement statement ...
 *              | var var var ... x N
 *              | var count = N
 */

#ifndef COCKTAIL_COT_PARSER_H
#define COCKTAIL_COT_PARSER_H

#include "cocktail.h"
#include "cot_util.h"
#include <stdlib.h>

// 利用token流分析语法
void parse(int VAR_LIST_SHOW, int PARSER_TREE_SHOW);

// 添加一个变量体
void add_var(cot_global_block *global, cot_var var);

// 显示内存中的变量
void show_var_list(cot_global_block *global);


#endif //COCKTAIL_COT_PARSER_H
