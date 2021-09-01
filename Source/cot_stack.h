/*
 * Created by Lettle on 2021/8/14.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */
#ifndef COMPILER_COT_STACK_H
#define COMPILER_COT_STACK_H

#define COT_STACK_HEADER int cot_stack_position;

struct cot_stack {
    COT_STACK_HEADER
};

extern int cop_stack_push(struct cot_stack *stack);
extern int cop_stack_pop(struct cot_stack *stack);

#endif //COMPILER_COT_STACK_H
