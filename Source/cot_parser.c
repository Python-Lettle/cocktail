/*
 * Created by Lettle on 2021/9/3.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */


#include "cocktail.h"
#include "cot_parser.h"

// 语法树分析

/**
 *  全局
 *  global_block:   statement_list      // 语句链表
 *                  var_list            // 变量 key:value
 *
 *  语句列表
 *  statement_list: statement (Linked Box)
 *
 *  语句
 *  statement:      expression SEMICOLON                    [ expression; ]
 *                  VAR define_expression_list SEMICOLON    [ var a; ]
 *                  STRUCT IDENTIFIER LC parameter_list RC SEMICOLON [struct name(int a, int b);]
 *                  RETURN expression SEMICOLON         [ return 0; ]
 *                  CONTINUE SEMICOLON                  [ continue; ]
 *                  BREAK SEMICOLON                     [ break; ]
 *                  function_definition_statement       // 函数声明语句
 *                  if_statement                        // 如果判断语句
 *                  for_statement                       // for循环语句
 *
 *  function_definition_statement:
 *                  FUNCTION IDENTIFIER LP parameter_list RP block
 *                  [ function hello(string str) {} ]
 *
 *  if_statement:   IF expression block             [ if a==0 {} ]
 *                  if_statement ELSE block         [ if a==0 {} else {} ]
 *                  if_statement ELSE if_statement  [ if a==0 {} else if {} ]
 *
 *  for_statement:  FOR expression_opt block        [ for () {} ]
 *                  FOR expression_opt SEMICOLON expression_opt SEMICOLON expression_opt block
 *                  [ for () ; () ; () {} ]
 *
 *  expression_opt: (empty)
 *                  expression
 *
 *  expression:     logical_or_expression [  ]
 *                  assignment_expression [  ]
 *
 *  define_expression_list:
 *                  define_expression                               [ int a; ]
 *                  define_expression_list COMMA define_expression  [ int a,b; ]
 *
 *  define_expression:
 *                  IDENTIFIER                  [ a ]
 *                  assignment_expression       [ a = 0 ]
 *
 *  assignment_expression:
 *                  IDENTIFIER ASSIGN expression        [ a = 0 ]
 *
 *  logical_or_expression:
 *                  logical_and_expression              [ a && b]
 *                  logical_or_expression LOGICAL_OR logical_and_expression
 *                                                      [ self || a&&b ]
 *  判等表达式
 *  equality_expression:
 *                  relational_expression                           [a>b]
 *                  equality_expression EQ relational_expression    [a==b]
 *                  equality_expression NE relational_expression    [a!=b]
 *
 *  关系表达式
 *  relational_expression:
 *                  additive_expression
 *                  relational_expression GT additive_expression
 *                  relational_expression GE additive_expression
 *                  relational_expression LT additive_expression
 *                  relational_expression LE additive_expression
 *
 *  additive_expression:
 *                  multiplicative_expression       [ a*b ] or [ a/b ]
 *                  additive_expression ADD multiplicative_expression [ a+b ]
 *                  additive_expression SUB multiplicative_expression [ a-b ]
 *
 *  一元表达式
 *  unary_expression:   primary_expression         [ a ]
 *                      SUB unary_expression        [ -a ]
 *                      INVERT unary_expression     [  ]
 *
 *  primary_expression: LP expression RP
 *                      INTEGER_LITERAL
 *                      FLOAT_LITERAL
 *                      STRING_LITERAL
 *                      IDENTIFIER
 *                      expression DOT IDENTIFIER
 *                      TRUE
 *                      FALSE
 *                      NEW IDENTIFIER LR argument_list RP
 *                      IDENTIFIER LP argument_list RP
 *                      IDENTIFIER LP RP
 *                      function_definition
 *
 *  argument_list:
 *                      expression
 *                      argument_list COMMA expression
 *
 *  function_definition:
 *                      FUNCTION LP parameter_list RP block
 *                      FUNCTION LP RP block
 *
 *  parameter_list:     IDENTIFIER
 *                      parameter_list COMMA IDENTIFIER
 *
 *  block:              LC RC
 *                      LC statement_list RC
 *
 */

/**
 * SEMICOLON    分号
 * unary        一元的
 * DOT          .
 */

//    示例
//    if((varname=check_var_name("testvar")))     strcpy(var.varname, varname);
//    var.value.type = INTEGER_LITERAL;
//    var.value.int_value = 233;
//    add_var(cot_global, var);
//
//    if((varname=check_var_name("hello")))       strcpy(var.varname, varname);
//    var.value.type = STRING_LITERAL;
//    strcpy(var.value.string_value,"Hello, world!");
//    add_var(cot_global, var);s

// 检查变量名的合法性
char * check_var_name(char varname[50]);
// 输出一个变量的信息(配合show_var_list使用)
void show_one_var(cot_var var);
// 输出语法树
void show_parser_tree(cot_node *);

unsigned int parse_function_call_exp(cot_node *node, cot_token *start);
unsigned int parse_int_var_define_exp(cot_node *node, cot_token *start);

void parse(int VAR_LIST_SHOW, int PARSER_TREE_SHOW)
{
    cot_global = (cot_global_block *) malloc(sizeof(cot_global_block));
    cot_global->var_count = 0;
    cot_global->vars = (cot_var *) malloc(sizeof(cot_var));

    cot_node *node = (cot_node *) malloc (sizeof(cot_node));

    cot_global->statement_list = node;

    cot_token *token_head = cot_token_head;

    while (token_head->value.type)
    {
        unsigned int next_time = 0;
        // 循环头为新的结点
        switch (token_head->value.type) {
            case IDENTIFIER:
                if(token_head->next->value.type == LP)
                    next_time = parse_function_call_exp(node, token_head);      // TODO: 暂且认定是调用函数
                break;
            case INT:
                if(token_head->next->value.type == IDENTIFIER)
                    next_time = parse_int_var_define_exp(node, token_head);
                break;
        }
        if(next_time)
            for(;next_time>0;next_time--)
                token_head = token_head->next;
        else
            token_head = token_head->next;
        node->next = (cot_node *) malloc(sizeof(cot_node));
        node = node->next;
    }

    //TODO: 目前只保存一个语法
    if(VAR_LIST_SHOW)
        show_var_list(cot_global);
    if(PARSER_TREE_SHOW)
        show_parser_tree(cot_global->statement_list);
}

void add_var(cot_global_block *global, cot_var var)
{
    global->var_count++;
    global->vars = (cot_var *) realloc (global->vars,VAR_LEN * global->var_count);
    global->vars[global->var_count-1] = var;
}

void show_var_list(cot_global_block *global)
{
    int i;
    printf("+--Var List---------------------------------------------------+\n");
    printf("|%-30s|%-25s|%4s|\n","varname","value","type");
    for(i=0;i<global->var_count;i++) {
        show_one_var(global->vars[i]);
    }
    printf("+-------------------------------------------------------------+\n");
}

void show_one_var(cot_var var)
{
    switch (var.value.type) {
        case INTEGER_LITERAL:
            printf(
                    "|%-30s|%-25d|%-4d|\n",
                    var.varname,
                    var.value.int_value,
                    var.value.type);
            break;
        case STRING_LITERAL:
            printf(
                    "|%-30s|%-25s|%-4d|\n",
                    var.varname,
                    var.value.string_value,
                    var.value.type);
    }

}

// 检查是否为合法varname
char * check_var_name(char varname[50]) {
    int i;
    for(i=0; i<50; i++) {
        if(!varname[i]) return varname;
        if(!(IsLetter(varname[i]) || IsDigit(varname[i]) || varname[i]=='_'))
        {
            return "";
        }
    }
    return varname;
}

/**
 * 语法分析方法
 * @param node      此语法对应结点
 * @param start     token起始处
 * @return
 */
unsigned int parse_function_call_exp(cot_node *node, cot_token *start)
{
    unsigned int next_time = 0;

    cot_node *node_term = (cot_node *) malloc (sizeof(cot_node));           // node_list 结点链表
    node->node_list = node_term;
    node->type = COT_FUNCTION_CALL_EXP;

    // 默认遇到 ; token 则停止此语句
    while (start->value.string_value[0] != ';')
    {
        switch (start->value.type) {
            case LP:
            case RP:
                break;
            case IDENTIFIER:
                node_term->type  = COT_FUNCTION_EXP;
                node_term->next = (cot_node *) malloc (sizeof(cot_node));
                node_term->token = start;
                node_term = node_term->next;
                break;
            case STRING_LITERAL:
                node_term->type  = COT_BLOCK_EXP;
                node_term->next = (cot_node *) malloc (sizeof(cot_node));
                node_term->token = start;
                node_term = node_term->next;
                break;
            default:
                break;
        }

        start = start->next; next_time++;
    }
    return next_time;
}
unsigned int parse_int_var_define_exp(cot_node *node, cot_token *start)
{
    unsigned int next_time = 0;
    cot_node *node_term = (cot_node *) malloc (sizeof(cot_node));           // node_list 结点链表
    node->node_list = node_term;
    node->type = COT_ASSIGN_EXP;
    while (start->value.string_value[0] != ';')
    {
        switch (start->value.type) {
            case ASSIGN:
            case STRING_LITERAL:
            case IDENTIFIER:
                node_term->type  = COT_BLOCK_EXP;
                node_term->next = (cot_node *) malloc (sizeof(cot_node));
                node_term->token = start;
                node_term = node_term->next;
                break;
            default:
                break;
        }

        start = start->next; next_time++;
    }
    return next_time;
}

// TODO: 目前只打印一个语法
void show_parser_tree(cot_node *tree)
{
    // 如果此结点空 则返回
    if(!tree) return;

    // 结点type判断
    if(tree->type) {
        switch (tree->type) {
            case COT_FUNCTION_CALL_EXP:
                printf("COT_FUNCTION_CALL_EXP\n");
                // 如果此结点包含表达式
                if (tree->node_list->type)
                    show_parser_tree(tree->node_list);
                break;
            case COT_FUNCTION_EXP:
                printf("| function (%d,%d): %s\n",tree->token->line, tree->token->ch, tree->token->value.string_value);
                show_parser_tree(tree->next);
                return;
            case COT_ASSIGN_EXP:
                printf("COT_ASSIGN_EXP ");
                switch (tree->token->value.type) {
                    case INT:
                        printf("(INT)");
                }
                printf("\n");
                // 如果此结点包含表达式
                if (tree->node_list->type)
                    show_parser_tree(tree->node_list);
                else if(tree->next)
                    show_parser_tree(tree->next);
                break;
            case COT_BLOCK_EXP:
                switch (tree->token->value.type) {
                    case ASSIGN:
                        printf("| ASSIGN (%d,%d): %s\n",tree->token->line, tree->token->ch, tree->token->value.string_value);
                        break;
                    case STRING_LITERAL:
                        printf("| string (%d,%d): %s\n",tree->token->line, tree->token->ch, tree->token->value.string_value);
                        break;
                    case IDENTIFIER:
                        printf("| identifier (%d,%d): %s\n",tree->token->line, tree->token->ch, tree->token->value.string_value);
                        break;
                    case INTEGER_LITERAL:
                        printf("| int (%d,%d): %d\n",tree->token->line, tree->token->ch, tree->token->value.int_value);
                        break;
                    case FLOAT_LITERAL:
                        printf("| float (%d,%d): %f\n",tree->token->line, tree->token->ch, tree->token->value.float_value);
                        break;
                }
                show_parser_tree(tree->next);
                return;
            default:
                printf("return back\n");
                return;
        }
    } else if (tree->token) {
        printf("| token\n");
        return;
    }

    // 下一个语法点
    if (tree->next) {
        show_parser_tree(tree->next);
        return;
    }
}