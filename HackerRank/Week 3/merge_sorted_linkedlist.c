SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* headA, SinglyLinkedListNode* headB) {
    // Create dummy node to simplify logic
    SinglyLinkedListNode dummy;
    SinglyLinkedListNode* tail = &dummy;
    dummy.next = NULL;

    // Traverse both lists
    while (headA != NULL && headB != NULL) {
        if (headA->data <= headB->data) {
            tail->next = headA;
            headA = headA->next;
        } else {
            tail->next = headB;
            headB = headB->next;
        }
        tail = tail->next;
    }

    // Attach remaining part
    if (headA != NULL) {
        tail->next = headA;
    } else {
        tail->next = headB;
    }

    return dummy.next;
}
