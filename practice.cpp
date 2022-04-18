#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head = NULL, *last = NULL;

void insertElement(int x)
{
    Node *p = new Node;
    p->data = x;
    p->next = NULL;
    if (head == NULL)
    {
        head = last = p;
    }
    else
    {
        last->next = p;
        last = p;
    }
}

Node Display(Node *p)
{
    while (p != NULL)
    {
        return Display(p->next);
        cout << p->data << " -> ";
    }
}

int main()
{
    int A[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < sizeof(A) / sizeof(A[0]); i++)
    {
        insertElement(A[i]);
    }
    Display(head);
}