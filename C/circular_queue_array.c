#include<stdio.h>         
#include<stdlib.h>       

#define max 5         

int front=-1,rear=-1;       
int CQueue[max];          

void Enqueue() {
    int n;
    if((front ==0 && rear == max-1) || front == rear+1)
    {
        printf("Circular Queue Is Full! Overflow!\n");
        return;
    }
    printf("Enter a number to Insert : ");
    scanf("%d",&n);
    if(front==-1)
        front=front+1;
    if(rear==max-1)
        rear=0;
    else rear=rear+1;
        CQueue[rear]=n;
}

void Dequeue() {
    int e;
    if(front==-1)
    {
        printf("The Circular Queue is Empty! Underflow!\n");
        return;
    }
    e=CQueue[front];
    if(front==max-1)
        front=0;
    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else front=front+1;
    printf("Deleting the number : %d\n",e);
}

void Peek() {
    printf("Front number of the queue is : %d\n", CQueue[front]);
}

void Display() {
    int i;
    if(front==-1)
    {
        printf("The Circular Queue is Empty! Nothing To Display!\n");
        return;
    }
    i=front;
    if(front<=rear)
    {
        while(i<=rear)
            printf("%d ",CQueue[i++]);
        printf("\n");
    }
    else
    {
        while(i<=max-1)
           printf("%d ",CQueue[i++]) ;
        i=0;
        while(i<=rear)
            printf("%d ",CQueue[i++]);
        printf("\n");
    }
}

int main() {

    int w;
    char ch;
   
    loop:
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Display\n");
    printf("5. EXIT\n");
    printf("Choose the option : ");
    scanf("%d",&w);
    switch(w)
    {
    case 1:
        Enqueue();
        break;
    case 2:
        Dequeue();
        break;
    case 3:
        Peek();
        break;
    case 4:
        Display();
        break;
    case 5:
        exit(1);
    default:
        printf("Invalid Choice!\n");
    }
    printf("Want to choose more? (Y/N) : ");
    scanf(" %c", &ch);
    if (ch=='Y' || ch=='y')
    goto loop;
    
    return 0;
}