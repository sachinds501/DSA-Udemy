// Create linked list by InsertLasting element at the last

#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    void InsertLast(int);
    void Display(Node *);
    int DeleteNode(Node *, int);
    int RCount(Node *);
} *head = NULL, *last = NULL;

void Node ::InsertLast(int x)
{
    Node *t = new Node;
    t->data = x;
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

void Node ::Display(Node *p)
{
    while (p != 0)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
}

int Node ::DeleteNode(Node *p, int index)
{
    Node *t = new Node;
    t = NULL;
    int x = -1, i;
    if (index < 1 || index > RCount(p))
        return -1;
    if (index == 1) // to remove 1st element
    {
        t = head;
        x = head->data;
        head = head->next;
        free(t);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++) // for traversing upto index
        {
            t = p;
            p = p->next;
        }
        t->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}

int Node ::RCount(Node *p)
{
    if (p == NULL)
        return 0;
    return RCount(p->next) + 1;
}

int main()
{
    Node L1;
    int A[] = {6, 45, 2, 6, 46, 45, 845};
    for (int x : A)
    {
        L1.InsertLast(x);
    }
    L1.DeleteNode(head, 2);
    L1.Display(head);
    // cout << endl
    //      << " Count is : " << L1.RCount(head) << endl;
}