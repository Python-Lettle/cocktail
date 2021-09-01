cmake_minimum_required(VERSION 3.13)
project(cocktail C)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE 1)

include_directories(Source/kernel)


set(SOURCE_FILES
    Source/kernel/cot_eval_exp.c
    Source/kernel/cot_exec.c
    Source/kernel/cot_expression.c
    Source/kernel/cot_runtime.c
    Source/kernel/cot_stack.c
    Source/kernel/cot_statement.c
    Source/kernel/cot_struct.c
    Source/kernel/cot_type.c)

add_executable(cocktail ${SOURCE_FILES})