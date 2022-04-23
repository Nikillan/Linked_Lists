//Took 2 hours to complete insert and delete operations 3.4.2022
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
}NODE;

NODE *head = NULL;
NODE *tail = NULL;

static int size = 0;
NODE* createNode(int num)
{
    size++;
    NODE *newNode;
    newNode = (NODE*)malloc(sizeof(NODE));
    newNode -> data = num;
    newNode -> next = NULL;
    return newNode;
}

void addFirst(int num)
{

    NODE *temp;
    temp = createNode(num);
    if(head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    temp -> next = head;
    head = temp;
}

void addLast(int num)
{

    NODE *temp;
    temp = createNode(num);
    if(head == NULL)
    {
        head = temp;
        tail = head;
        return;
    }
    tail -> next = temp;
    tail = temp;
}

void add(int pos, int num)
{

    NODE *th = head, *temp = NULL;
    if(pos <= 0)
    {
        addFirst(num);
        return;
    }
    if(pos >= size)
    {
        addLast(num);
        return;
    }
    printf("while ");
    while(pos > 1 && pos < size)
    {

        th = th -> next;
        pos--;
    }
    temp = createNode(num);
    temp -> next = th -> next;
    th -> next= temp;
}
void deleteFirst()
{
    NODE *temp;
    if(head == NULL)    //To check if the list is empty
    {
        printf("Empty List\n");
        return;
    }
    size--;
    if(head -> next == NULL)    //To check if the list has only one element.
    {
        free(head);
        head = tail = NULL;
        return;
    }
    temp = head;
    head = head -> next;
    free(temp);
    temp = NULL;
}
void deleteLast()   //In SLL we cannot access the previous element
{
    NODE *th1, *th2;
    if(tail == NULL) //To check if the list is empty
    {
        printf("Empty List\n");
        return;
    }
    size--;
    if(head -> next == NULL)    //To check if the list has only one element
    {
        free(head);
        head ==  NULL;
    }
    th2 = head;
    th1 = th1 -> next;
    while(th2 != tail)
    {
        th1 = th1 -> next;
        th2 = th2 -> next;
    }
    tail  = th2;
    tail -> next = NULL;
    free(th1);
    th1 = th2 = NULL;
}
void del(int pos)
{
    NODE *t1, *temp;
    t1 = head;
    if(head == NULL)
    {
        printf("Empty List");
    }
    else
    {
        if(pos <= 0)
        {
            deleteFirst();
            return;
        }
        if(pos >= size - 1)
        {
            deleteLast();
            return;
        }
        while(pos > 1)
        {
            t1 = t1 -> next;
            pos--;
        }

        temp = t1 -> next;
        t1 -> next = temp -> next;
        free(temp);
        temp = NULL;
    }
}
void main()
{
    NODE *t1;
    t1 = (NODE*)malloc(sizeof(NODE));
    deleteFirst();
//    printf("1 ");
    addFirst(10);
  //  printf("2 ");
    addLast(20);
    //printf("3 ");
    add(10, 40);
//    printf("4 ");
    add(18, 30);
    deleteLast();
  //  printf("5\n");
  //  add(10, 60);
    //printf("6\n");
    add(-20, 50);
    del(2);

    t1 = head;
    printf("size: %d \n", size);

    while(t1 != NULL)
    {
        printf("%d\n", t1 -> data);
            t1 = t1 -> next;
    }
}
