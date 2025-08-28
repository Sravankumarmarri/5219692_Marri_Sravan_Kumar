DoublyLinkedListNode* reverse(DoublyLinkedListNode* head) {
    if (head == NULL) return NULL;

    DoublyLinkedListNode* curr = head;
    DoublyLinkedListNode* temp = NULL;

    // Traverse the list
    while (curr != NULL) {
        // Swap next and prev
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        // Move to the next node in original order (which is prev now)
        curr = curr->prev;
    }

    // After loop, temp will be at the new head's prev
    if (temp != NULL) {
        head = temp->prev;
    }

    return head;
}
