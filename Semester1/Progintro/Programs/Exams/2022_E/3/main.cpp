struct Node {
    int data;
    Node* next;
};

typedef Node* list;

int sumDeletedEven(list& head) {
    int sum = 0;

    if (head == nullptr) return 0;

    Node* node = head;
    head = head -> next;
    sum += node->data;
    delete node;

    node = head;

    while (node != nullptr && node->next != nullptr) {
        Node* temp = node->next;
        node->next = temp->next;

        sum += temp->data;
        delete temp;

        node = node->next;
    }

    return sum;
}