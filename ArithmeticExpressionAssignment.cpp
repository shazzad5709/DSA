//  Shazzad Hossain
//BSSE 1203

#include<string.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<ctype.h>
using namespace std;
char stack[100];
int top = -1, head=-1;
int sum[1000];

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

string numToStr(int x)
{
    string str="";
    int k;
    while(x!=0)
    {
        k=x%10;
        str+=k+'0';
        x/=10;
    }
    reverse(str.begin(),str.end());
    return str;    
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    return 0;
}

int calc(int a, int b, char c)
{
    int r;
    if(c=='+')
        r=a+b;
    else if(c=='-')
        r=a-b;
    else if(c=='*')
        r=a*b;
    else if(c=='/')
        r=a/b;
    return r;

}

int evaluation(string s)
{
    int op1,op2,result=0,number=0;
    string::iterator it;
    for(it=s.begin(); it< s.end(); it++)
    {
        if(*it==' ')
            continue;
        else if (isalnum(*it))
        {
            if(!isalnum(*(it-1)))
                number=0;
            number=number*10+*it-'0';
            if(!isalnum(*(it+1)))
                sum[++head]=number;
        }
        else
        {
            op2=sum[head--];
            op1=sum[head--];
            result=calc(op1, op2, *it);
            sum[++head]=result;
        }
    }
    return result;
}

int main()
{
    char exp[100];
    string pf="";
    char *e, x;
    int num=0, i=0;
    printf("Infix expression: ");
    scanf("%s",exp);
    printf("Postfix expression: ");
    e = exp;
    
    while(*e != '\0')
    {
        if(isalnum(*e))
        {
            if(!isalnum(*(e-1)))
                num=0;
            num=num*10+*e-'0';
            if(!isalnum(*(e+1)))
            {
                cout<<num<<", ";
                pf+=numToStr(num);
                pf+=" ";
            }
        }
        else if (*e == ' ')
            continue;
        else if(*e == '(')
            push(*e);
        else if(*e == ')')
        {
            while((x = pop()) != '(')
            {
                cout<<x;
                pf+=x;
                pf+=" ";
                if(top>=-1 && i!=strlen(exp)-1)cout<<", ";
            }
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            {
                x=pop();
                pf+=x;
                pf+=" ";
                printf("%c",x);
                if(top>=-1 && i!=strlen(exp)-1)cout<<", ";
            }
            push(*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        x=pop();
        pf+=x;
        pf+=" ";
        printf("%c",x);
        if(top>=0)
            cout<<", ";
    }
    // cout<<endl<<pf;
    cout<<endl<<"Value: ";
    int  yyy=evaluation(pf);
    cout<<yyy;
    return 0;
}
