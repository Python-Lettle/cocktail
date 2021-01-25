#include <stdio.h>
#include <string.h>

char* token_get(char *token)
{
    char *p;
    p = strtok(token,";");
    return p;
}

int token_ana(char *token)
{
    char *fun_name; //函数名
    char fun_n[10];
    char *args; //参数
    int i=1;
    
    fun_name = strtok(token,"(");
    while(fun_name){
        switch (i++)
        {
        case 2:
            printf("%s\n",fun_name);
            break;
        }
        fun_name = strtok(NULL, "('");
    }
    return 0;
}
