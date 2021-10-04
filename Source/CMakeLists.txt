cmake_minimum_required(VERSION 3.13)
project(cocktail C)


set(CMAKE_CXX_STANDARD 14)
set(CMAKE_VERBOSE_MAKEFILE 1)

set(SOURCE_FILES
    cot_debug.c
    cot_stack.c
    cot_lexer.c
    cot_parser.c
    cot_util.c
    main.c)

add_executable(cocktail ${SOURCE_FILES})