#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
}typedef NODE;

NODE *head = NULL, *tail = NULL;

NODE* createNode(int gd)
{
    NODE *newNode;
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> data = gd;
    newNode -> next = NULL;
    return newNode;
}

void list(int gd)
{
    NODE *temp, *th;
    temp = createNode(gd);
    if(head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    tail -> next = temp;
    tail = temp;
}

void reverse()
{
    NODE *curr, *prev, *skip;

    curr = head;
    skip = curr -> next;
    prev = curr;

    curr -> next = NULL;
    curr = skip;

    while(skip)
    {
        skip = skip -> next;
        curr -> next = prev;
        prev = curr;
        curr = skip;
    }
    head = prev;
}

void main()
{
    char ch;
    int givenData;
    NODE *th;

    do
    {
        scanf("%d%c", &givenData, &ch);
        list(givenData);
    }while(ch != '\n');

    reverse();

    th = head;
    while(th)
    {
        printf("%d ", th -> data);
        th = th -> next;
    }
}
