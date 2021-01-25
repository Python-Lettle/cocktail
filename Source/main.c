#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../Include/token.h"

int main(int argc,char *argv[])
{
    //读取参数
    int i;
    printf("接收的参数---------\n");
    for (i=0;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    printf("-------------------\n");
    //读取源码
    FILE *fp;
    char load_file[]="source.let";//文件名
    char line[100]={0};//读取的最大字符
    //scanf("%s",load_file);
    fp=fopen(load_file,"r");//打开文件

    if(fp==NULL){
        printf("Error: can't open source\n");
        return 1;
    }
    
    //一行一行获取代码
    char *nline;
    while(fgets(line,100,fp)){
        nline = token_get(line);
        token_ana(nline);
    }

    fclose(fp);
    return 0;
}
