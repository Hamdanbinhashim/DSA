#include<stdio.h>
void main()
{
    int stack[100],top=-1,choice,value;
    printf("Stack menu\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.exit\n");
    do
    {
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                if(top==100-1)
                    printf("Stack overflow!\n");
                else
                {
                    printf("Enter value to push:");
                    scanf("%d",&value);
                    stack[++top]=value;
                }
                break;
            case 2:
                if(top==-1)
                    printf("Stack underflow!\n");
                else
                {
                    printf("Top:%d\n",stack[top]);
                    top--;
                }
                break;
            case 3:
                if(top==-1)
                    printf("Stack underflow!\n");
                else
                    printf("Top:%d\n",stack[top]);
                break;
            case 4:
                if(top==-1)
                    printf("Stackunder flow!\n");
                else
                {
                    printf("Stack elements:\n");
                    for (int i=top; i>=0; i--)
                        printf("%d ",stack[i]);
                }
                printf("\n");
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid input!\n");
                break;
        }
    } while(choice!=5);
}
