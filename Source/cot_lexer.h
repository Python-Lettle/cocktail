/*
 * Created by Lettle on 2021/8/15.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COT_LEXER_H
#define COCKTAIL_COT_LEXER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cot_util.h"
#include "cot_debug.h"

struct cot_token_stream{
    // 容量
    int capacity;
    // token数量
    int count;
    // 储存的token
    cot_token *tokens;
};


void cot_token_scan(FILE * fpin);
void cot_token_stream_add(cot_token token);


#endif //COCKTAIL_COT_LEXER_H
