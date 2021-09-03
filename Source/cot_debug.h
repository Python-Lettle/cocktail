/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COT_DEBUG_H
#define COCKTAIL_COT_DEBUG_H

#include <stdio.h>

// 是否开启debug模式
#define __DEBUG_MODE__ 1

// 是否输出token分析过程
#define __TOKEN_ANA_PROCESS__ 0

// TODO: 这里要写一个cocktail专用报错机制
void cot_err(char *msg);

#endif //COCKTAIL_COT_DEBUG_H
