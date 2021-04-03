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
/**----------语法分析器----------**/


/**----------代码生成器----------**/
string asm_print();
string asm_string(string str);
string asm_main();
string asm_head();
void generate(map<int,Token> m)
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
	map<int,Token>::iterator it;
	it = m.begin();
	while(it!=m.end()){
		if(it->second.type==STRING){
			out_asm += asm_string(it->second.source);
		}
		it++;
	}
	//cout << "Finish"<<endl;

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
	

	//参数分析
	//fpin=fopen(argv[1],"r");
	int ASM_SOURCE_MODE = 0;
	for(int i=1;i<argc;i++){
		if(!strcmp(argv[i],"-S")){
			ASM_SOURCE_MODE = 1;
		}else{
			fpin=fopen(argv[i],"r");
			break;
		}
	}

    //cout<<"1.词法分析"<<endl;
	

	
    map<int,Token> tokens;
    tokens = ana(fpin);
    
	/*
    cout <<"Tokens----------------"<<endl;
    showTokens(tokens);
	*/
	generate(tokens);
	
	if(ASM_SOURCE_MODE == 0){
		system("gcc test.s -o tester");
		system("rm test.s");
	}

    return 0;
}

