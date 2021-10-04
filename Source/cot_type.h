/*
 * Created by Lettle on 2021/8/14.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COMPILER_COT_TYPE_H
#define COMPILER_COT_TYPE_H

// 一个token最长多少字节
#define token_length_maximum 50

typedef struct {
    int type;
    union {
        char string_value[token_length_maximum];
        int int_value;
        int boolean_value;
        double float_value;
    };
} cot_value;



#endif //COMPILER_COT_TYPE_H
