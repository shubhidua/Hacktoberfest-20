#include<stdio.h>
#include<stdlib.h>

struct LL
{
    int data;
    struct LL *next;
};

// Function to return number of nodes in linked list
int ListTraverse (struct LL **head) {
    struct LL *current = *head;
    int count = 0;
    while(current){
        count++;
        current = current -> next;
    }
    return count;
}

// Function to print linked list 
void ListPrint (struct LL **head) {
    struct LL *current = *head;
    while(current){
        printf("%d -> ", current -> data);
        current = current -> next;
    }
    printf("NULL \n");
}

// Function to insert node at the beginning of the list
void InsertStart (struct LL **head, int data) {
    struct LL *temp, *newNode;
    temp = *head;
    newNode = (struct LL *)malloc(sizeof(struct LL));
    newNode -> data = data;
    newNode -> next = temp;
    *head = newNode;
    ListPrint(head);
}

// Function to insert node at the last position of the list
void InsertEnd (struct LL **head, int data) {
    struct LL *p, *newNode;
    newNode = (struct LL *)malloc(sizeof(struct LL));
    newNode -> data = data;
    newNode -> next = NULL;

    if (*head == NULL) {
        *head = newNode;
        printf("The linked list is not created yet, therefore inserting at first position, \n");
    }
    else {
        int count=0;
        p = *head;

        while (p -> next!=NULL)
        {
            p = p->next;
            count++;
        }
        p -> next = newNode;
    }
    ListPrint(head);
}

// Function to insert node at the specific position of the list
void InsertPosition (struct LL **head, int data , int position) {

    struct LL *p, *q, *newNode;
    int k=1;
    newNode = (struct LL *)malloc(sizeof(struct LL));
    newNode -> data = data;
    p=*head;
    if (*head == NULL) {
        *head = newNode;
        printf("The linked list is not created yet, therefore inserting at first position, \n");
    }
    else if (position == 1) {
        newNode->next = p;
        *head = newNode;
    }
    else {
        while (p != NULL && k<position) {
            q = p;
            p = p->next;
            k++;
        }
        if (k != position)
        printf("Given position exceeds the total number of nodes, therefore inserting at the end. \n");

        q ->next = newNode;
        newNode->next = p;
    }
    ListPrint(head);
}



int main() {

    struct LL *head = NULL;

    int opt = 0, count = 0;
    char c='N';
    int n=0,f=0,d=0,p=0;

    loop:;
    
    printf("\n");
    printf("1. Append nodes. \n");
    printf("2. Insert new node at start. \n");
    printf("3. Insert new node at end. \n");
    printf("4. Insert new node at position. \n");
    printf("5. Traverse List. \n");
    printf("6. Print list. \n\n");
    printf("Choose your option : ");
    scanf("%d",&opt);

    switch (opt)
    {

    case 1 :
        printf("Enter no. of nodes : ");
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
        {
            printf("Enter the data of node %d : ",i);
            scanf("%d",&d);
            InsertEnd(&head,d);
        }
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;
        break;

    case 2 :
        printf("Enter the data of node 1 : ");
        scanf("%d",&f);
        InsertStart(&head,f);
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;
        break;

    case 3 :
        printf("Enter the data of last node : ");
        scanf("%d",&d);
        InsertEnd(&head,d);
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;
        break;

    case 4 :
        printf("Enter the position : ");
        scanf("%d", &p);
        printf("Enter the data of node %d : ",p);
        scanf("%d",&d);
        InsertPosition(&head,d,p);
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;
        break;
    
    case 5 :
        count = ListTraverse(&head);
        printf("Total number of nodes in Linked List : %d\n", count);
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;

    case 6 :
        ListPrint(&head);
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;
        break;

    default:
        printf("Wrong option \n");
        printf("\n");
        printf("Want to choose more?(Y/N) : ");
        scanf(" %c",&c);
        // clear screen function in linux
        system("clear"); // Use < system("cls"); > in windows
        if (c=='y' || c=='Y')
        goto loop;
        break;

    }

    return 0;
    
}