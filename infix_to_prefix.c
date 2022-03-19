#include<stdio.h>
#include<ctype.h>
#include<string.h>
int top=-1;
char stack[10];
void push(char c){
    stack[++top]=c;
}
char pop(){
    return(stack[top--]);
}
int priority(char ch){
    if(ch=='*'||ch=='/'){
        return 2;
    }
    else if(ch=='+'||ch=='-'){
        return 1;
    }
    else{
        return 0;
    }
}
void main()
{
    char prefix[10],infix[10];
    int i=0,j=0,k=0;
    printf("enter the infix expression: ");
    scanf("%s",infix);
    strrev(infix);
    char ch=infix[0];
    printf("%s\n",infix);
    while(ch!='\0'){
        if(ch=='('){
            push(ch);
        }
        else if(isdigit(ch)||isalpha(ch))
        {
            prefix[j]=ch;
            j++;
        }
        else if(ch==')'){
            char x;
            x=pop();
            while(ch!='('){
                prefix[j]=x;
                j++;
                x=pop();
            }
            push(x);
        }
        else if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
            if(priority(ch)<=priority(stack[top])){
                while(priority(ch)<=priority(stack[top])){
                    prefix[j]=pop();
                    j++;
                }
                push(ch);
            }
            else{
                push(ch);
            }
        }
        i++;
        ch=infix[i];
    }
    if(top!=-1){
        while(top!=-1){
            prefix[j]=pop();
            j++;
        }
    }
    strrev(prefix);
    printf("%s",prefix);
}
