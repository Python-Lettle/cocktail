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
#include "cocktail.h"

void cot_token_scan(FILE * fpin, int showToken);

void cot_token_show(cot_token *token1);

#endif //COCKTAIL_COT_LEXER_H
