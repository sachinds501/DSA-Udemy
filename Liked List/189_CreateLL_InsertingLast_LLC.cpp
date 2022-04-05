// Create linked list by InsertLasting element at the last

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // public:
    void InsertLast(int);
    void Display(Node *p);
    void RDisplay(Node *p);
    int RCount(Node *p);
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

int Node ::RCount(Node *p1)
{ // don't return without if else
    if (p1 == NULL)
    {
        return 0;
    }
    else
        return RCount(p1->next) + 1;
}

void Node ::RDisplay(Node *p)
{
    // Base case
    if (p == NULL)
        return;

    // print the list after head node
    RDisplay(p->next);

    // After everything else is printed, print head
    cout << p->data << " -> ";
}

int main()
{
    Node L1;
    int A[] = {6, 45, 2, 6, 46, 45, 845};
    for (int x : A)
    {
        L1.InsertLast(x);
    }

    // Insertion at first

    Node *newNode = new Node();
    newNode->data = 80;
    newNode->next = head;
    head = newNode;

    // Insertion at last

    Node *newNode2 = new Node();
    newNode2->data = 70;
    newNode2->next = NULL;
    Node *p = new Node();
    p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode2;

    // Insertion at random, insert at 3rd position

    int pos = 3;
    Node *random = new Node();
    random->data = 69;
    Node *p2 = new Node();
    p2 = head;
    while (pos - 2 > 0)
    {
        p2 = p2->next;
        pos--;
    }
    random->next = p2->next;
    p2->next = random;

    // Deletion of 1st element
    head = head->next;

    // Deletion at last
    Node *p3 = new Node();
    p3 = head;
    while (p3->next && p3->next->next)
    {
        p3 = p3->next;
    }
    p3 = NULL;

    // deletion at random, delete the 3rd element

    int pos2 = 3;
    Node *p4 = new Node();
    p4 = head;
    while (pos2 - 2 > 0)
    {
        p4 = p4->next;
        pos2--;
    }
    p4->next = p4->next->next;

    Node *p5 = new Node();
    p5 = head;
    while (p5->next->data != 845 && p5->next->next)
    {
        p5 = p5->next;
    }
    p5->next = p5->next->next;

    L1.Display(head);
    cout << endl
         << "Count is : " << L1.RCount(head) << endl;
    // L1.RDisplay(head);
}