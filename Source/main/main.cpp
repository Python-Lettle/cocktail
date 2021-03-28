#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>

#include "globals.h"
#include "util.h"

using namespace std;

/**返回每个字的值**/
template <class T>
int value(T *a,int n,T str){
	for(int i=0;i<n;i++){
		if(a[i]==str) return i+1;
	}
	return -1;
}

/** 显示词法分析结果 **/
void showTokens(map<int,Token> tokens);

/**----------词法分析器----------**/
map<int,Token> ana(FILE * fpin);

/**----------代码生成器----------**/
string asm_print()
{
	string print_asm = 
		"\t.globl print\n"
		"print:\n"
    	"\tstp x29, x30, [sp, #-16]!\n"
		"\tmov x29, sp\n"
		"\tbl  puts\n"
		"\tldp x29, x30, [sp], #16\n"
		"\tret";
	return	print_asm;
}
string asm_string()
{
	string string_asm =
		".helstr:\n"
		"\t.asciz\t\"hello\"\n"
		"\t.size\t.helstr, 6";
	return string_asm;
}
string asm_main()
{
	string main_asm =
	"main:\n"
    "\tstp x29, x30, [sp, #-16]!\n"
    "\tadrp    x0, .helstr\n"
    "\tadd x0, x0, :lo12:.helstr\n"
	"\tmov x29, sp\n"
    "\tbl  puts\n"
	"\tmov w0, wzr\n"
	"\tldp x29, x30, [sp], #16\n"
	"\tret\n";
	return main_asm;
}
string asm_head()
{
	string head_asm =
		"\t.globl main\n";
	return head_asm;
}
void general()
{
		
	string prt_asm =
		"\t.global print\n"
		"print:\n"
		"\tb\tputs";

	string out_asm = 
		"\t.text\n";
	FILE *out;
	out = fopen("test.s","w+");

	out_asm += asm_head();
	out_asm += asm_main();
	out_asm += asm_string();

	fprintf(out,"%s",out_asm.c_str());
	// fputs(print_asm.c_str(), out);
	fclose(out);

}

/**----------主函数----------**/
int main(int argc,char *argv[])
{
    char inFile[40];
    string analysed; 
    FILE *fpin;
    //cout<<"File name:";
    //cin>>inFile;
    //fpin=fopen("src.cot","r");
	fpin=fopen(argv[1],"r");
    //cout<<"1.词法分析"<<endl;
	

	/*
    map<int,Token> tokens;
    tokens = ana(fpin);
    
    cout <<"Tokens----------------"<<endl;
    showTokens(tokens);
	*/
	general();
	system("gcc test.s -o tester");
	system("rm test.s");

    return 0;
}


