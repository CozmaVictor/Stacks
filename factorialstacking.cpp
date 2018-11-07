#include<iostream>
using namespace std;
typedef struct {
    int content[100];
    int top;
} stack;
int push(stack *S,int some)
{
    if ((*S).top<100) {
        (*S).top++;
        (*S).content[(*S).top]=some;
        return 1;
    }
    return 0;
}
int pop(stack *S,int *some)
{
    if ((*S).top>=1) {
        *some=S->content[S->top];
        S->top--;
        return 1;
    }
    return 0;
}
int initstack(stack *S)
{
    (*S).content[0]=1;
    S->top=0;
    return 1;
}
int printstack(stack S)
{
    cout<<endl;
    int index;
    for(index=1;index<=S.top;index++)
    {
        cout<<S.content[index]<<" ";
    }
    return 1;
}
stack S;
int main()
{
    int directie = 1;
    int x;
    cout<<"x=";
    cin>>x;
    initstack(&S);
    for(int i=x;i>=1;i--)
    {
        push(&S,i);
    }
    int y1,y2;
    while(S.top>1)
    {
        if(directie == 0)
        {
            pop(&S,&y1);
            pop(&S,&y2);
            push(&S,y1*y2);
        }
        else
        {
            pop(&S,&y1);
            if(y1 == 1){
                push(&S,y1);
                directie = 0;
            }
            else{
                push(&S,y1);
                push(&S,y1-1);
            }
        }
        }
        printstack(S);
    return 0;
}
