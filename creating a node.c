#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct Node
{
    int data;
    struct Node *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

NODE* createNode(int val)
{
    NODE *newNode;
    newNode = malloc(sizeof(NODE));
    newNode -> data = val;
    newNode -> next = NULL;
    if(head == NULL)
    {
        head = newNode;
        tail = head;
    }
    printf("Successful %d\n", newNode -> data);
    return newNode;
}

void addFirst(int val)
{
    NODE *temp;
    temp = createNode(val);
  /*  if(head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }*/
    temp -> next = head;
    head = temp;
    //printf("%d %d\n", head -> next -> data, head -> next);
}

void addLast(int val)
{
    NODE *temp;
    temp = createNode(val);
 /*   if(head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }*/
    temp -> next = tail;
    tail = temp;
    //printf("%d %d\n", head -> next -> data, head -> next);
}

int getN(int index)
{
    int count = 0;
    NODE *current = head;
    while(current != NULL)
    {
        if(count == index)
            return (current -> data);
        current = current -> next;
        count++;
    }
    return 0;
  //  assert(0);
}
void main()
{
    //createNode(10);
    addFirst(20);
    addFirst(10);
    addLast(30);
    addFirst(40);
    printf("%d\n", getN(3)) ;
    printf("%d %d %d %d\n", head -> data, head -> next -> data,head -> next -> next -> data, tail -> data);

}
