#include <iostream>
#include <map>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

//关键字
string KEYWORD[15]={
    "package","import",
    "if","else","void","return",
    "while","for","do",
    "int","string","double","float"};

//常量
const string SEPARATE = "分隔符";
const string OPERATE = "运算符";
const string VAR = "变量名";
const string KEY = "关键字";
const string NUM = "数字";
const string BOOLEAN = "布尔值";
const string STRING = "字符串";

//分隔符
char SEPARATER[8]={';',',','{','}','[',']','(',')'};
//运算符
char OPERATOR[8]={'+','-','*','/','>','<','=','!'};
//过滤符
char FILTER[4]={' ','\t','\r','\n'};

//Token结构
struct Token 
{
    int line;   //行号
    int ch;     //字符位置
    string type;   //Tonen类型
    string source;//源代码

};

/*--------- 函数 ---------*/
/**判断是否为关键字**/
bool IsKeyword(string word){
    for(int i=0;i<15;i++){
        if(KEYWORD[i]==word){
            return true;
        }
    }
    return false;
}
/**判断是否为分隔符**/
bool IsSeparater(char ch){
    for(int i=0;i<8;i++){
        if(SEPARATER[i]==ch){
            return true;
        }
    }
    return false;
}
 
/**判断是否为运算符**/
bool IsOperator(char ch){
    for(int i=0;i<8;i++){
        if(OPERATOR[i]==ch){
            return true;
        }
    }
    return false;
}
/**判断是否为过滤符**/
bool IsFilter(char ch){
    for(int i=0;i<4;i++){
        if(FILTER[i]==ch){
            return true;
        }
    }
    return false;
}
/**判断是否为大写字母**/
bool IsUpLetter(char ch){
    if(ch>='A' && ch<='Z') return true;
    return false;
}
/**判断是否为小写字母**/
bool IsLowLetter(char ch){
    if(ch>='a' && ch<='z') return true;
    return false;
}
/**判断是否为数字**/
bool IsDigit(char ch){
    if(ch>='0' && ch<='9') return true;
    return false;
}
/**返回每个字的值**/
template <class T>
int value(T *a,int n,T str){
	for(int i=0;i<n;i++){
		if(a[i]==str) return i+1;
	}
	return -1;
}

/**词法分析**/
map<int,Token> ana(FILE * fpin)
{
    const string TABLE = "\t\t\t";

    char ch=' ';     //取一个字符
    string arr="";   //用ch连接字符串
    Token t; 
    int counter = 0; //记录token数
    int line = 0;  //当前行号
    int char_count;//当前字符位置
    map<int,Token> result; //返回tokens

    string type="None"; //程序当前采集类型
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
            //继续获取小写字母
            while(IsLowLetter(ch+1)){
                //如果下一位还是小写字母则加入
				arr += ch;
				ch=fgetc(fpin);
            }
			//fseek(fpin,-1L,SEEK_CUR);
			if(IsKeyword(arr)){
				cout<<arr<<TABLE<<KEY<<endl;
			}
            else{
                //继续获取大小写字母
                while(IsLowLetter(ch+1)||IsUpLetter(ch+1)){
                    arr += ch;
                    ch = fgetc(fpin);
                }
                cout <<arr<<TABLE<<VAR<<endl;
            }
            
                
        }
        //判断数字
        else if(IsDigit(ch)){
            while(IsDigit(ch)){
                arr += ch;
                /*
                if(IsSeparater(ch+1))
                    break;
                    */
                ch = fgetc(fpin);
                
            }
            cout <<arr<<TABLE<<NUM<<endl;
        }
        //判断符号
        switch(ch){
        case '"':
            {
                arr += ch;//将双引号加入
                ch=fgetc(fpin);//跳到下一字符
                while(ch!='"'){
                    arr+=ch;ch=fgetc(fpin);
                }
                arr += ch;
                cout <<arr<<TABLE<<STRING<<endl;
                break;
            }
        case '+':
        case '-':
        case '*':
        case '/':
        case '>':
        case '<':
        case '=':
        case '!':
            {
                arr += ch;
                cout<<arr<<TABLE<<OPERATE<<endl;
                break;
            }
        case ';':
            {
                cout<<ch<<TABLE<<";"<<endl;
                break;
            }
        case ',':
        case '(':
        case ')':
            {
                cout<<ch<<TABLE<<SEPARATE<<endl;
                break;
            }
        case '[':
        case ']':
        case '{':
        case '}':
            {
              arr += ch;
              cout<<arr<<TABLE<<SEPARATE<<endl;
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

    return result;
}
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
    ana(fpin);

    return 0;
}

/*
void paster()
{
//模式控制
        switch(type){
            case NO:
            {
                if(IsDigit(ch)){type = NUM;}
                else if(IsLowLetter(ch)){type=WD;}
                else if(IsUpLetter(ch)){type=VAR;}
                else if(IsOperator(ch)){type=OPERATE;}
                arr += ch;
                break;
            }
            case KEY:
                {

                    break;
                }
            case VAR:
                {
                    break;
                }
            case SEPARATE:
                {
                    break;
                }
            case OEPRATE:
                {
                    break;
                }
            default: cout <<"default"<<endl;
        }}
*/
