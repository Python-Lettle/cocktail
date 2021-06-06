#include <stdio.h>
#include <map>
#include <string>
#include "util.h"
#include "globals.h"
using namespace std;
void syntax_error(int type){
    /*
     * 1 语句错误
     * */
    printf("Syntax error.\n");
}
void syntax(map<int,Token> tokens,bool prt)
{
    map<int,Token>::iterator it;
    it = tokens.begin();
    string varname_temp,string_temp;
    string varnames[10];
    string strings[10];
    int string_amount=0;
    while(it!=tokens.end()){
        //先判断语句第一个词汇

        //变量名
		if(it->second.type==VAR){
            varname_temp = it->second.source;
            
            /* print */
            if(it->second.source=="print"){
                it++;
                // print(
                if(it->second.source=="("){
                    it++;
                    // print( str
                    if(it->second.type==STRING){
                        string_temp = it->second.source;
                        printf("Function: print -> %s\n",string_temp.c_str());
                    // print( varname
                    }else if(it->second.type==VAR){
                        printf("Function: print -> [%s]\n",it->second.source.c_str());
                    }
                }
            }   
            
            it++;    
            //变量名 =
            if(it->second.source=="="){
                it++;
                //变量名 = STRING
                if(it->second.type==STRING){
                    string_amount++;
                    varnames[string_amount] = varname_temp;
                    strings[string_amount] = it->second.source;
                    if(prt)
                        printf("Eval: %s -> %s\n",varname_temp.c_str(),strings[string_amount].c_str());
                }
            }
        //关键字
		}else if(it->second.type==KEY){
        }else {
            //printf("Unknown: %s\n",it->second.source.c_str());
        }
		it++;
	}
}
