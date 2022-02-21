
    Node *p4 = new Node();
    p4 = head;
    while (pos2 - 2 > 0)
    {
        p4 = p4->next;
    }
    p4->next = p4->next->next;