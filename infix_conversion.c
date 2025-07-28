#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#define MAX 100

char stack[MAX];
int top=-1;
int intStack[MAX];
int topInt = -1;

void pushInt(int val) {
    intStack[++topInt] = val;
}

int popInt() {
    if (topInt == -1)
        return 0;
    return intStack[topInt--];
}


void push(char c)
{
   stack[++top]=c;
}

char pop()
{
   if(top==-1)
      return '\0';
   return stack[top--];      
}

char peek()
{
   if(top==-1)
       return '\0';
   return stack[top];
}

int precedence(char c)
{
   if(c=='^')
      return 3;
   if(c=='*' || c=='/')
      return 2;     
   if(c=='+' || c=='-')
      return 1;
   return 0;
}

void reverse(char* str)
{
   int n=strlen(str);
   for (int i=0;i<n/2;i++)
   {
      char temp=str[i];
      str[i]=str[n-i-1];
      str[n-i-1]=temp;
   }
}

void infixConvert(char* infix,char* result,const char* mode)
{
   top=-1;
   char temp[MAX];
   strcpy(temp,infix);
   if(strcmp(mode,"prefix")==0)
   {
      reverse(temp);
      for(int i=0;temp[i]!='\0';i++)
      {
         if(temp[i]=='(') temp[i]=')';
         else if(temp[i]==')') temp[i]='(';
      }
   }
   int k=0;
   for(int i=0;temp[i]!='\0';i++)
   {
      char c=temp[i];
      if(isalnum(c))
         result[k++]=c;
      else if(c=='(')
         push(c);
      else if(c==')')
      {
        while (top != -1 && peek() != '(')
            {
                result[k++] = pop();
            }
            pop();
      }
      else
      {
         while (top != -1 && precedence(peek()) >= precedence(c))
         {
            result[k++] = pop();
         }
            push(c);
      }
   }
   while(top!=-1)
      result[k++]=pop();
   result[k]='\0';
   if(strcmp(mode,"prefix")==0)
      reverse(result);
}

int evaluatePostfix(char* expr) {
    int i = 0;
    while (expr[i] != '\0') {
        char ch = expr[i];

        // If operand (single-digit number), convert char to int and push
        if (isdigit(ch)) {
            int val = ch - '0';
            pushInt(val);
        } 
        else {
            // Operator: pop two values and apply operator
            int val2 = popInt();
            int val1 = popInt();

            switch (ch) {
                case '+': pushInt(val1 + val2); break;
                case '-': pushInt(val1 - val2); break;
                case '*': pushInt(val1 * val2); break;
                case '/': 
                    if (val2 == 0) {
                        printf("Division by zero\n");
                        return 0;
                    }
                    pushInt(val1 / val2); break;
                case '%':
                    if (val2 == 0) {
                        printf("Modulo by zero\n");
                        return 0;
                    }
                    pushInt(val1 % val2); break;
                case '^':
                    pushInt((int)pow(val1, val2)); break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
        }
        i++;
    }
    return popInt();
}

void main()
{
   char infix[MAX],result[MAX];
   int ch;
   printf("1.Number expression\n2.General expression\nEnter choice:");
   scanf("%d",&ch);
   printf("Enter infix expression:");
   scanf("%s",infix);
   infixConvert(infix,result,"prefix");
   printf("Prefix expression: %s\n",result);                
   infixConvert(infix,result,"postfix");
   printf("Postix expression: %s\n",result); 
   if (ch==1)
   {
       int res=evaluatePostfix(result);   
       printf("Expression result: %d\n",res);   
   }    
}            
      
      
      
      
      
      
               
           
