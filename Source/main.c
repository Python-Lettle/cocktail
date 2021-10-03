/*
 * Created by Lettle on 2021/8/14.
 * QQ: 1071445082
 * github: https://github.com/Python-Lettle
 * gitee : https://gitee.com/lettle/
 */


#include <string.h>
#include "cot_debug.h"
#include "cot_lexer.h"
#include "cot_parser.h"

// 程序传入参数是否显示token
int ARG_TOKEN = 0;
int VAR_LIST_SHOW = 0;
FILE *fp;

// 编译器帮助信息
static void usage(int exitcode) {
    fprintf(exitcode ? stderr : stdout,
            "Usage: cocotail [ -E ][ -a ] [ -h ] <file>\n\n"
            "\n"
            "  -I<path>          add to include path\n"
            "  -E                print preprocessed source code\n"
            "  -D name           Predefine name as a macro\n"
            "  -D name=def\n"
            "  -S                Stop before assembly (default)\n"
            "  -c                Do not run linker (default)\n"
            "  -U name           Undefine name\n"
            "  -fdump-ast        print AST\n"
            "  -fdump-stack      Print stacktrace\n"
            "  -fno-dump-source  Do not emit source code as assembly comment\n"
            "  -o filename       Output to the specified file\n"
            "  -g                Do nothing at this moment\n"
            "  -Wall             Enable all warnings\n"
            "  -Werror           Make all warnings into errors\n"
            "  -O<number>        Does nothing at this moment\n"
            "  -m64              Output 64-bit code (default)\n"
            "  -w                Disable all warnings\n"
            "  -h                print this help\n"
            "\n"
            "One of -a, -c, -E or -S must be specified.\n\n");
    exit(exitcode);
}

int main(int argc, char *argv[]) {
    if(argc == 1) {
        usage(1);
    }

    // 参数解析
    for (int i=1;i < argc;i++){
        if(!strcmp(argv[i],"-h") || !strcmp(argv[i], "--help")){
            usage(0);
        }else if(!strcmp(argv[i],"--token")) {
            // 是否输出token分析过程
            ARG_TOKEN = 1;
        } else if(!strcmp(argv[i],"--varlist")){
            VAR_LIST_SHOW = 1;
        } else {

            fp = fopen(argv[i], "r");   // 用文件名尝试打开

            // 打开文件失败
            if (!fp) {
                printf("Please check your paramer.\n");
                usage(1);   // 用信号1表示异常退出
            }
        }
    }

    // 打开文件成功
    cot_token_scan(fp, ARG_TOKEN);
    parse(VAR_LIST_SHOW);

    return 0;
}


