// Write a program to demonstrate the stack operations (Push, Pop, Peek, Display) using Array.

#include<stdio.h>

int data[5];
int top;

int push() {

    int x;

    if(top==4) {
        printf("Stack Overflow \n");
    } else {
        printf("Enter the element : ");
        scanf("%d",&x);
        top=top+1;
        data[top]=x;
    }

    return 0;
}

int pop() {

    int x;
    
    if(top==-1) {
        printf("Stack underflow");
    } else {
        x=data[top];
        printf("Element popped is : %d \n",x);
        top=top-1;
    }

    return 0;
}

int peek() {

    if(top==-1) {
        printf("Stack is empty \n");
    } else {
        printf("Top element is : %d \n",data[top]);
    }

    return 0;
}

int display() {

    if(top==-1) {
        printf("Stack is empty \n");
    } else {
        printf("\n");
        for(int i=top;i>=0;i--) {
            printf("%d\n",data[i]);
        }
    }
        printf("\n");

    return 0;
}

int main() {

    top=-1;
    int n;
    char c;

    loop:
    printf("\n");
    printf("1. Push \n");
    printf("2. Pop \n");
    printf("3. Peek \n");
    printf("4. Display \n");
    printf("5. Exit \n");
    printf("Choose your option : ");
    scanf("%d", &n);

    switch (n)
    {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            return 0;
            break;
        default:
            break;
    }

    printf("Want to choose more? (Y/N) ");
    scanf(" %c", &c);

    if (c == 'Y' || c == 'y')
        goto loop;

    return 0;
}