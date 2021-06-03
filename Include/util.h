#include <string>
#include <stdlib.h>
using namespace std;

#define keywordSum 15

//常量
const string SEPARATE = "分隔符";
const string OPERATE = "运算符";
const string VAR = "变量名";
const string KEY = "关键字";
const string NUM = "数字";
const string BOOLEAN = "布尔值";
const string STRING = "字符串";
const string CONST = "常量";

//关键字
const string KEYWORD[keywordSum]={
    "package","import",
    "if","else","void","return",
    "while","for","do",
    "int","string","double","float"};

const string VARTYPE[4]={
	"int","string","double","float"
};


//分隔符
const char SEPARATER[8]={';',',','{','}','[',']','(',')'};
//运算符
const char OPERATOR[8]={'+','-','*','/','>','<','=','!'};
//过滤符
const char FILTER[4]={' ','\t','\r','\n'};

/*--------- 函数 ---------*/

bool IsKeyword(string word);
bool IsSeparater(char ch);
bool IsOperator(char ch);
bool IsFilter(char ch);
bool IsUpLetter(char ch);
bool IsLowLetter(char ch);
bool IsDigit(char ch);

