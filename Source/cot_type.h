/*
 * Created by Lettle on 2021/8/14.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COMPILER_COT_TYPE_H
#define COMPILER_COT_TYPE_H

#include "cot_stack.h"

typedef struct {
    COT_STACK_HEADER;
    int type;
    union {
        int int_value;
        int boolean_value;
        char * string_value;
        double float_value;
    };
} cot_value;



#endif //COMPILER_COT_TYPE_H
