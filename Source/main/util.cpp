#include "../../Include/util.h"
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
