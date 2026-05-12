#include <cstdio>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void swap(Node* n1, Node* n2) {
    int temp = n1 -> data;
    n1 -> data = n2 -> data;
    n2 -> data = temp;
}

void sortList(Node* list) {
    if (list == nullptr || list->next == nullptr) return;
    
    Node* lastSorted = nullptr;
    bool swapped;

    do {
        swapped = false;
        Node* front = list->next;
        Node* back = list;

        while (front != lastSorted) {
            if (back->data > front->data) {
                swap(back, front);
                swapped = true;
            }
            back = back->next;
            front = front->next;
        }
        lastSorted = back;
    } while (swapped);
}