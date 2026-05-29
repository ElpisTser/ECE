#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swap(Node* n1, Node* n2) {
    int temp = n1->data;
    n1->data = n2->data;
    n2->data = temp;
}

void sort(Node* list) {
    if (list == nullptr || list->next == nullptr)
        return;

    Node* lastChecked = nullptr;
    
    while (lastChecked != list->next) {
        Node* node = list;
        bool swapped = false;

        while (node->next != lastChecked) {
            Node* nextNode = node->next;
            if (node->data > nextNode->data) {
                swap(node, nextNode);
                swapped = true;
            }
            node = nextNode;
        }

        if (!swapped) break;
        lastChecked = node;
    }
}