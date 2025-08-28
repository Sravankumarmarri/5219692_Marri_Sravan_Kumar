SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    // Create new node
    SinglyLinkedListNode* newNode = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    newNode->data = data;
    newNode->next = NULL;

    // Case 1: Insert at head
    if (position == 0) {
        newNode->next = head;
        return newNode;
    }

    // Traverse to (position - 1)th node
    SinglyLinkedListNode* current = head;
    for (int i = 0; i < position - 1 && current != NULL; i++) {
        current = current->next;
    }

    // Insert node
    newNode->next = current->next;
    current->next = newNode;

    return head;
}
