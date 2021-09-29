/*
 * Created by Lettle on 2021/9/3.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COT_PARSER_H
#define COCKTAIL_COT_PARSER_H

#include "cocktail.h"
#include "cot_util.h"
#include <stdlib.h>

// 利用token流分析语法
void parse();

/**
 * global_block:
 *              | statement statement statement ...
 *              | var var var ... x N
 *              | var count = N
 */

// 初始化一个全局块
void init_global_block(cot_global_block_tag *global);

// 添加一个空变量体
void add_var(cot_global_block_tag *global, cot_var var);

// 显示内存中的变量
void show_var_list(cot_global_block_tag *global);


#endif //COCKTAIL_COT_PARSER_H
