#include<stdio.h>
#include<string.h>
#define SIZE 100
typedef struct stack{
    int arr[SIZE];
    int top;
}STACK;

typedef enum bool {FALSE,TRUE}BOOL;
void Create_Stack(STACK *m);
void Initialize_Stack(STACK *m);
BOOL isEmpty(STACK s);
BOOL isFull(STACK s);
int push(STACK *s,int d);
int pop(STACK *s,int *d);
int peep(STACK s);
int automorph(int n);

int main()
{int n1;
STACK arr;
Create_Stack(&arr);
STACK arr2;
Create_Stack(&arr2);
printf("\nAUTOMORPHIC NUMBER\n");
printf("\nThis code checks whether the number entered by the user is an Automorphic number.\nThis is implemented using the Abstract Data Type - Stacks.");
printf("\nA number is called Automorphic number if and only if its square ends in the same digits as the number itself.\nEnter a few numbers\n");
printf("\nEnter the count of numbers to be checked:");
scanf("%d",&n1);
{
    for(int i=0;i<n1;i++)
    {
        int num;
        printf("Enter number %d:",i+1);
        scanf("%d",&num);
        push(&arr,num);
    }
    for(int i=0;i<n1;i++)
    {
        int item1;
        pop(&arr,&item1);
        push(&arr2,item1);
    }
    for(int i=0;i<n1;i++)
    {
        int item1;
        pop(&arr2,&item1);
        automorph(item1);}
}

}

int automorph(int n)
{
    STACK s;
    Create_Stack(&s);
    STACK s1;
    Create_Stack(&s1);
    int temp;
    temp=n;
    int rem=0,count=0;
    while(temp)
        {rem=temp%10;
        push(&s,rem);
        temp=temp/10;
        count+=1;
        }
    int temp1=n*n;
    int rem1=0,count1=0;
    while(temp1)
        {rem1=temp1%10;
        push(&s1,rem1);
        temp1=temp1/10;
        count1+=1;
        }
    int c;
    c=count1-count;
    for (int i=0;i<c;i++)
    {
        int item;
        pop(&s1,&item);
    }
    int flag=0;
    for (int i=0;i<count;i++)
    {
        int item1,item2;
        pop(&s,&item1);
        pop(&s1,&item2);
        if(item1==item2)
        {flag=1;}
    }
    printf("\nThe number you have entered:%d\n\n",n);
    printf("The square of the number you have entered:%d\n\n",n*n);
    if (flag==1)
        {
            printf("The number entered is automorphic as the last %d digits are same as the number entered\n",count);
        }
    else
        {
            printf("The number entered is not automorphic as the last %d digits are same as the number entered",count);
        }
    }

void Create_Stack(STACK *m)
{
    m->top=0;
}

BOOL isEmpty(STACK s){
    return (s.top==0);
}

BOOL isFull(STACK s){
    return (s.top==SIZE-1);
}

int push(STACK *s,int d){
    if(!isFull(*s))
    {
        s->top+=1;
        s->arr[s->top]=d;
        return 1;
    }
    return 0;
}

int pop(STACK *s,int *d)
{
    if(!isEmpty(*s))
    {
        *d=s->arr[s->top];
        s->top=s->top-1;
          return 1;
    }
    return 0;
}

int peep(STACK s){
    if(isEmpty(s))
        return -1;
    return s.arr[s.top];
}
