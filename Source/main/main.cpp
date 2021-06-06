#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>

#include "globals.h"
#include "util.h"

using namespace std;


/**----------词法分析器----------**/
map<int,Token> scan(FILE * fpin);
/** 显示词法分析结果 **/
void showTokens(map<int,Token> tokens);

/**----------语法分析器----------**/
void syntax(map<int,Token> tokens,bool prt);
// 获取语句流


//语法结构

// 赋值
// var = value;
int VOLUATION_ID = 1;
string VOLUATION[4] = {
	string(VAR),
	string(1,OPERATOR[6]),
	CONST,string(1,SEPARATER[0])};

// 定义函数
// KEYWORD VARNAME (){
int DEFINE_ID = 2;
string DEFINE[] = {
	string(KEY),
	string(VAR),
	string(1,SEPARATER[6]),
	string(1,SEPARATER[7]),
	string(1,SEPARATER[2])};

//获取语句
/*
map<int,string[]> get_sentence(map<int,Token> m)
{
	map<int,Token>::iterator it;
	Token now;
	for(it = m.begin();it!=m.end();it++){
		now = it->second;
		if(now.source != ";"){
		}
	}
	return m;
}
*/

//语法分析
bool parsing(map<int,Token> m)
{
	return true;	
}

/**----------代码生成器----------**/
#include "asm.h"
void generate(map<int,Token> m)
{
		
	string prt_asm =
        ".globl print\n"
	    "\t.def	print;	.scl	2;	.type	32;	.endef\n"
        "print:\n"
	    "\tpushl	%ebp\n"
    	"\tmovl	%esp, %ebp\n"
	    "\tcall	_printf\n"
	    "\t.def	___main;	.scl	2;	.type	32;	.endef;\n";

	string out_asm = 
		"\t.text\n";
	FILE *out;
	out = fopen("test.s","w+");

    /*
	out_asm += asm_head();
	out_asm += asm_main();
    */

	map<int,Token>::iterator it;
	it = m.begin();
    int string_count = 0;
    char * string_name;
    /*
	while(it!=m.end()){
		if(it->second.type==STRING){
            string_count++;
            string_name = "LC" + string_count + "0";
			out_asm += asm_string(string_name,it->second.source);
		}else if(it->second.type==VAR){
			if(it->second.source=="print"){     
				out_asm += asm_print(".content");
			}
		}
		it++;
	}
    */
    //out_asm += asm_main_end();

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

	/** 参数分析 **/

	int ASM_SOURCE_MODE = 0;
	int SHOW_TOKENS = 0;
	string outname = "tester";	//文件名
	for(int i=1;i<argc;i++){
		if(!strcmp(argv[i],"-S")){
			ASM_SOURCE_MODE = 1;
		}else if(!strcmp(argv[i],"--tokens")){	
			SHOW_TOKENS = 1;
        }else if(!strcmp(argv[i],"--syntax")){ 
            SHOW_TOKENS = 2;
		}else if(!strcmp(argv[i],"-o")){
			i++;
			outname = argv[i];
		}else if(!strcmp(argv[i],"-h") || !strcmp(argv[i],"--help")){
			printf("%s\n",HELP_MSG);
			return 0;
		}else{
			fpin=fopen(argv[i],"r");
			if(!fpin)
				cout <<"Please check your parameter."<<endl;
		}
	}
	
	/** 词法分析 **/
    map<int,Token> tokens;
    tokens = scan(fpin);
	if(SHOW_TOKENS != 0){
        cout<<"Token scanner:"<<endl;
		showTokens(tokens);
        if(SHOW_TOKENS == 2){
            cout<<"Syntax result:"<<endl;
            syntax(tokens,true);
        }
		return 1;
	}

	/** 语法分析 **/
	//syntax(tokens);

	/** 汇编代码生成 **/

	generate(tokens);
	
	if(ASM_SOURCE_MODE == 0){
		string compile ="gcc test.s -o "+outname;
		system(compile.c_str());
		system("rm test.s");
	}

    return 0;
}

