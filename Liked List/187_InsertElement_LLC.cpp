#include <iostream>
using namespace std;

class Node
{
    int data;
    Node *next;

public:
    void Create(int *A, int n);
    void Display(Node *);
    void Insert(Node *, int index, int value);
    int count(Node *);
} *head = NULL; // head pointer

void Node ::Create(int *A, int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
    { // temporary variable
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
};

void Node ::Display(Node *p)
{
    while (p != 0)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
};

int Node ::count(Node *p)
{
    if (p == 0)
    {
        return 0;
    }
    else
        return count(p->next) + 1;
};

/* To insert between the list*/
void Node ::Insert(Node *p, int index, int value)
{
    // Node *p = new Node;
    if (index < 0 || index > count(p))
    {
        return;
    }
    else
    {
        // to insert at index
        for (int i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        Node *newNode = new Node;
        newNode->data = value;
        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
        }
        else

        
        {
            newNode->next = p->next;
            p->next = newNode;
        }
    }
}

int main()
{
    Node L1;
    int A[] = {5, 6, 8, 4, 2};

    L1.Create(A, 5);
    // index and value to put on it.
    L1.Insert(head, 0, 13);
    L1.Display(head);
}

// Well Done but more practice needed.