#include <iostream>
using namespace std;

class Node
{
    int data = 0;
    Node *next;

public:
    void InsertLast(int);
    void InsertSorted(Node *, int);
    void RDisplay(Node *);
} *head = NULL, *last = NULL;

void Node ::InsertLast(int i)
{
    Node *t = new Node;
    t->data = i;
    t->next = NULL;

    if (head == NULL)
    {
        head = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}

void Node ::RDisplay(Node *p)
{
    if (p == NULL)
    {
        return;
    }
    cout << p->data << " -> ";
    RDisplay(p->next);
}

void Node ::InsertSorted(Node *p, int x)
{
    Node *q, *t = new Node;

    t->data = x;
    t->next = NULL;

    if (head == NULL)
        head = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == head)
        {
            t->next = head;
            head = t;
        }
        else
        { 
            t->next = q->next;
            q->next = t;
            // q = t;
        }
    }
}

int main()
{
    Node L1;
    int A[] = {10, 15, 20, 25, 30, 35, 40, 45, 50};
    for (int x : A)
    {
        L1.InsertLast(x);
    }
    L1.InsertSorted(head, 2);
    L1.InsertSorted(head, 21);
    L1.InsertSorted(head, 64);
    L1.RDisplay(head);
}