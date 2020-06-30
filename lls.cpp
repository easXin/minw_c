#include <iostream>

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;
    public:
        LinkedList(){
            first!=NULL;
        }
        LinkedList(int A[],int n);
        // destructor
        ~LinkedList();
        void Display();
        void Insert(int index,int x);
        void Delete(int index);
        void DeleteFromHead();
        int Length();
};

LinkedList::LinkedList(int A[], int n){
    int i;
    // t: temp ptr, last traces the ele of linkedlist
    Node *t, *last;
    //first = (struct Node *)malloc(sizeof(struct Node));
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList(){
    Node *p = first;
    while(first){
        first=first->next;
        delete p;
        p= first;
    }
}
void LinkedList::Display()
{
    Node *p = first;
    while (p != NULL)
    {
        printf("%d  ", p->data);
        p = p->next;
    }
}
int LinkedList::Length(){
    Node *p = first;
    int i = 0;
    while (p != NULL)
    {
        i++;
        p = p->next;
    }
    return i;
}

void LinkedList::Insert( int x, int index)
{
    Node *t;
    Node *p = first;
    if (index < 0 || index > Length())
    {
        return;
    }
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->next = p;
        first = t;
    }
    else
    {
        Node *q;
        for (int i = 0; i < index; i++)
        {
            q = p;
            p = p->next;
        }

        if (p->next == NULL)
        {
            p->next = t;
            t->next = NULL;
        }
        else
        {
            q->next = t;
            t->next = p;
        }
    }
}
void LinkedList::DeleteFromHead()
{
    Node *p = first;
    if (p == NULL)
    {
        printf("This linkedlist contains no element");
        return;
    }
    Node *q;
    q = p->next;
    first->next = q;
    first = q;
}
void LinkedList::Delete(int index)
{
    Node *p = first;
    Node *q;
    int x;
    if (index < 0 || index > Length())
    {
        printf("Invalid index\n");
        return;
    }
    else
    {
        if (index == 0)
        {
            DeleteFromHead();
        }
        else
        {
            for (int i = 0; i < index - 1; i++)
            {
                p = p->next;
            }
            if (p->next->next == NULL)
            {
                p->next = NULL;
            }
            else
            {
                p->next = p->next->next;
            }
        }
    }
}