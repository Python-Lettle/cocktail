#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>

#include "../../Include/util.h"

using namespace std;

/**返回每个字的值**/
template <class T>
int value(T *a,int n,T str){
	for(int i=0;i<n;i++){
		if(a[i]==str) return i+1;
	}
	return -1;
}
//Token结构
struct Token
{
    int line;   //行号
    int ch;     //字符位置
    string source;//源代码
    string type;   //Tonen类型

    Token(int li,int c,string sou,string tp):line(li),ch(c),source(sou),type(tp){}
};


/** 显示词法分析结果 **/
void showTokens(map<int,Token> tokens)
{
    map<int,Token>::iterator it;
    for(it=tokens.begin();it!=tokens.end();it++){
        cout<<it->first
            <<"\t"<<it->second.line<<":"<<it->second.ch
            <<"\t"<<it->second.source
            <<"\t"<<it->second.type
            <<endl;
    }
    return;
}

/**----------词法分析器----------**/
map<int,Token> ana(FILE * fpin)
{
    const string TABLE = "\t\t\t";
    Token t = {0,0,"a","n"};
    char ch=' ';     //取一个字符
    string arr="";   //用ch连接字符串 
    int counter = 0; //记录token数
    int line = 1;  //当前行号
    int char_count=0;//当前字符位置
    map<int,Token> result; //返回tokens

    do{
        //循环获取字符
        ch = fgetc(fpin);
        if(feof(fpin)){break;};//EOF则停止
        char_count++;
        arr = "";
        //判断过滤符
        if(ch=='\n'){
            line++;char_count=0;
            continue;} //行数增加

        if(IsFilter(ch)){continue;}
        
        //判断关键字或变量名
        else if(IsLowLetter(ch)){
            t.ch = char_count;
            //继续获取小写字母
            while(IsLowLetter(ch+1)){
                //如果下一位还是小写字母则加入
				arr += ch;
				ch=fgetc(fpin);
                char_count++;
            }
			//fseek(fpin,-1L,SEEK_CUR);
            t.line = line;
            t.source = arr;
			if(IsKeyword(arr)){
                t.type = KEY;
				cout<<arr<<TABLE<<KEY<<endl;
			}
            else{
                //继续获取大小写字母
              while(IsLowLetter(ch+1)||IsUpLetter(ch+1)){
                arr += ch;ch = fgetc(fpin);char_count++;}
                t.type = VAR;
                cout <<arr<<TABLE<<VAR<<endl;
            }
            result.insert(pair<int,Token>(++counter,t));
        }
        //判断数字
        else if(IsDigit(ch)){
            t.ch = char_count;
            while(IsDigit(ch)){
                arr += ch;ch = fgetc(fpin);char_count++;}
            t.line = line;
            t.source = arr;
            t.type = NUM;
            result.insert(pair<int,Token>(++counter,t));
            cout <<arr<<TABLE<<NUM<<endl;
        }
        //判断符号
        switch(ch){
        case '"':
            {
                arr += ch;//将双引号加入
                ch=fgetc(fpin);//跳到下一字符
                t.ch = char_count;
                char_count++;
                while(ch!='"'){
                    arr+=ch;ch=fgetc(fpin);char_count++;}
                arr += ch;
                t.line = line;
                t.source = arr;
                t.type = STRING;
                result.insert(pair<int,Token>(++counter,t));

                cout <<arr<<TABLE<<STRING<<endl;
                break;
            }
        case '+':
        case '-':
        case '*':
        case '/':
            {
                arr = ch;
                ch = fgetc(fpin);char_count++;
                if(ch=='/'){
                    //进入单行注释模式
                    while(ch!='\n'){
                    arr=ch;ch=fgetc(fpin);}
                line++;char_count=0;
                continue;} //行数增加
                if(ch=='*'){
                    //进入多行注释模式
                    do{

                    while(ch!='*'){
                        if(ch=='\n'){line++;char_count=0;}
                        ch=fgetc(fpin);
                    }
                    ch=fgetc(fpin);
                    if(ch=='/'){break;}
                    else if(feof(fpin)){break;};//空停止

                    
                    }while(1);
                    
                }
                break;
            }
        case '>':
        case '<':
        case '=':
        case '!':
            {
                t.line = line;
                t.ch = char_count;
                t.source = ch;
                t.type = OPERATE;
                result.insert(pair<int,Token>(++counter,t));
                arr += ch;
                cout<<arr<<TABLE<<OPERATE<<endl;
                break;
            }
        case ';':
            {
                t.line = line;
                t.ch = char_count;
                t.source = ch;
                t.type = ";";
                result.insert(pair<int,Token>(++counter,t));
                cout<<ch<<TABLE<<";"<<endl;
                break;
            }
        case ',':
        case '(':
        case ')':
            {
                //t = {line,char_count,ch,SEPARATE};
                t.line = line;
                t.ch = char_count;
                t.source = ch;
                t.type = SEPARATE;
                result.insert(pair<int,Token>(++counter,t));
                cout<<ch<<TABLE<<SEPARATE<<endl;
                break;
            }
        case '[':
        case ']':
        case '{':
        case '}':
            {
                //t = {line,char_count,ch,SEPARATE};
                t.line = line;
                t.ch = char_count;
                t.source = ch;
                t.type = SEPARATE;
                result.insert(pair<int,Token>(++counter,t));

                cout<<ch<<TABLE<<SEPARATE<<endl;
                break;
            }
        
        default :
            {
            if(ch!=' ')
                cout<<"("<<ch<<")"<<":无法识别的字符！"<<endl;
            }
        }
        //if(!arr.empty()){result.insert(pair<int,Token>(counter++,arr))}
       
    }while(1);
    //cout <<counter<<endl;
    return result;
}

/**----------主函数----------**/
int main()
{
    char inFile[40];
    string analysed; 
    FILE *fpin;
    //cout<<"File name:";
    //cin>>inFile;
    fpin=fopen("src.txt","r");
    cout<<"词法分析: "<<endl;

    map<int,Token> tokens;
    tokens = ana(fpin);
    
    cout <<"Tokens----------------"<<endl;
    showTokens(tokens);
    return 0;
}


