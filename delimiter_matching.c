#include<stdio.h>
char st[50];
int top=-1;
void push(char t){
    st[++top]=t;
}
char pop()
{
    return st[top--];
}
void main()
{
    char ch[50];
    int f=0;
    printf("enter string");
    scanf("%s",ch);
    int i=0;
    while(ch[i]!='\0')
    {
        if(ch[i]=='('||ch[i]=='['||ch[i]=='{')
            push(ch[i]);
        else if(ch[i]==')'||ch[i]==']'||ch[i]=='}')
        {
            if(top==-1){
            f=0;
            break;}
            else
            {
                char x=pop();
               if(x=='('&&ch[i]==')'||x=='['&&ch[i]==']'||x=='{'&&ch[i]=='}')
               f=1;
               else{
                   f=0;
                   break;
               }
            }
        }i++;
    }
    if(top!=-1)
    f=0;
    if(f==1)
    printf("valid");
    else
    printf("Invalid");
}
