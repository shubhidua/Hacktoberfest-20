#include<stdio.h>
#include<stdlib.h>

struct List {
    int data;
    struct List *next;
};

void ListPrint(struct List **head) {
    struct List *current = *head;
    while (current != NULL){
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n\n");
}

void ListInsert(struct List **head, int data) {
    struct List *p, *node;
    p = *head;
    node = (struct List *)malloc(sizeof(struct List));
    node->data = data;
    node->next = NULL;
    if (*head == NULL) {
        *head = node;
    } else {
        while (p->next != NULL){
            p = p->next;
        }
        p->next = node;
    }
    
}

void ReverseIterative(struct List **head) {
    struct List *prev, *current, *next;
    current = *head;
    prev = NULL;
    next = NULL;
    while(current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

void ReverseRecursion(struct List **head, struct List *p) {
    if(p-> next == NULL) {
        *head = p;
        return;
    }

    ReverseRecursion(head, p->next);

    struct List *rev;
    rev = p->next;
    rev->next = p;
    p->next = NULL;
}

int main() {
    struct List *head;
    head = NULL;
    int n, data, s;
    printf("Enter number of nodes : ");
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        printf("Enter the data of node %d : ", i);
        scanf("%d", &data);
        ListInsert(&head,data);
    }
    ListPrint(&head);
    printf("Reverse List Using :\n");
    printf("1. Iterative Method \n");
    printf("2. Recursive Method \n");
    printf("Choose your option : ");
    scanf("%d", &s);
    switch (s)
    {
    case 1:
        ReverseIterative(&head);
        ListPrint(&head);
        break;
    case 2:
        ReverseRecursion(&head, head);
        ListPrint(&head);
        break;
    default:
        printf("Wrong option. \n");
        break;
    }
   
    return 0;
}