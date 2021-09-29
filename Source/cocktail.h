/*
 * Created by Lettle on 2021/9/7.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COCKTAIL_COCKTAIL_H
#define COCKTAIL_COCKTAIL_H
#include "cot_util.h"

typedef struct cot_token_stream_tag{
    // 容量
    int capacity;
    // token数量
    int count;
    // 当前读取位置缓存
    int now;
    // 储存的token
    cot_token *tokens;
}cot_token_stream;

// 全局token流
cot_token_stream cot_ts;

typedef struct
{
    cot_node statement_list;        // 语句链表
    unsigned short var_count;       // 变量数量
    cot_var *vars;              // 变量数组
} cot_global_block_tag;

// 全局块
cot_global_block_tag cot_global;

#endif //COCKTAIL_COCKTAIL_H
