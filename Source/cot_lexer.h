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

typedef struct cot_token_stream_tag{
    // 容量
    int capacity;
    // token数量
    int count;
    // 储存的token
    cot_token *tokens;
}cot_token_stream;

// 全局token流
cot_token_stream cot_ts;

void cot_token_scan(FILE * fpin, int showToken);

void cot_token_stream_init ();
void cot_token_stream_add(cot_token token, int showToken);
cot_token cot_token_stream_get(int index);

void cot_token_show(cot_token token);

#endif //COCKTAIL_COT_LEXER_H
