#include<stdio.h>
#include<stdlib.h>

struct LL {
    int data;
    struct LL *next;
};

struct LL *top=NULL;

void display () {
    struct LL *current = top;
    printf("TOP -> ");
    while(current){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("\n");
}

void push() {
    struct LL *newNode;
    newNode = malloc(sizeof(struct LL));
    if (newNode==NULL) {
        printf("Error! Overflow");
        return;
    }

    int data;
    printf("Enter the data : ");
    scanf("%d", &data);

    if (top==NULL) {
        top = newNode;
        newNode->data = data;
        newNode->next = NULL;
    }

    else {
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }
}

void pop() {
    struct LL *node;
    if (top == NULL) {
        printf("Underflow!!! \n");
        return;
    } else {
        node = top;
        printf("Element popped is : %d \n", node->data);
        top = node->next;
        free(node);
    }
}

void peek() {
    if (top == NULL) {
        printf("Stack is empty \n");
    } else {
        printf("Top element is : %d \n", top->data);
    }
}

int main() {

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