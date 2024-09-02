#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int pres(char ch)
 {
    if(ch=='^'){
        return 3;
    }
    else if(ch == '/' || ch == '*')
    return 2;
    else if(ch == '+' || ch == '-')
    return 1;
    else
    return -1;       
}
char itp(char expression[])
{
    char res[50];
    int resindex=0;
    int sindex =0;
    char stk[50];
    int len = strlen(expression);
    for(int i=0;i<len;i++){
        char ch = expression[i];
        if((ch>='a' && ch<='z') ||( ch>='A' && ch<='Z')){
            res[resindex++] =ch;
            // resindex++; 
        }
        else if(ch=='('){
            stk[sindex++]='(';
            // sindex++;
        }
        else if(ch==')'){
            while(sindex>0 && stk[sindex-1]!='('){
                res[resindex++]=stk[--sindex];
            }
            sindex--;
        }
        else{
            while(sindex>0 && pres(expression [i])<=pres(stk[sindex-1])){
                res[resindex++]=stk[--sindex];
            }
            stk[sindex++]=ch;
        }
    }
            while(sindex>0){
                res[resindex++]=stk[--sindex];
            }
            res[resindex]='\0';
            printf("%s",res);
    
}
int main()
{
    char expression[] = "((x+(y*z))-w)";   
    itp(expression);   
    return 0;   
}