/*
 * Created by Lettle on 2021/8/14.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COMPILER_COT_STACK_H
#define COMPILER_COT_STACK_H
#include "cot_util.h"

// 变量链表
typedef struct {
    /* 变量名 */
    char *name;
    /* 变量值 */
    cot_value value;
    /* 下一个变量，组成一个链表 */
    struct Variable *next;
} Variable;

#endif //COMPILER_COT_STACK_H
