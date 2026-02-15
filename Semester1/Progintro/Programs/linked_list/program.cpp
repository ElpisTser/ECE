#include <cstdio>

struct node {
    int info;
    node* next;
};

typedef node* list;

void printList(list listStart) {
    while (listStart->next != nullptr) {
        printf("%d ", listStart->info);
        listStart = listStart->next;
    }
    printf("%d\n", listStart->info);
}

node* search(list listStart, int data) {
    node* currentNode;
    for (currentNode=listStart; currentNode->next!=nullptr; currentNode=currentNode->next) 
        if (currentNode->info == data) return currentNode;
    return nullptr;
}

void insertAtRear(list &listStart, int data) {
    node* newNode = new node;
    node* currentNode;
    
    newNode->info = data;
    newNode->next = nullptr;

    if (listStart == nullptr)
        listStart = newNode;
    else {
        currentNode = listStart;
        while (currentNode->next != nullptr)
            currentNode = currentNode->next;
        currentNode->next = newNode;
    }
}

void insertAfter(node* prevNode, int data) {
    node* newNode = new node;
    newNode->info = data;
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteAfter(node* prevNode) {
    if (prevNode != nullptr && prevNode->next != nullptr) {
        node* noteToDelete = prevNode->next;
        prevNode->next = noteToDelete->next;
        delete noteToDelete;
    } else {
        printf("No node to delete");
    }
}

void concat(list &list1, list list2) {
    if (list1 == nullptr) {
        list1 = list2;
        return;
    }
    if (list2 == nullptr) return;
    
    node* currentNode = list1;
    while (currentNode->next != nullptr) {
        currentNode = currentNode->next;
    }
    currentNode->next = list2;
}

void reverseList(list &list) {
    node* prevNode = nullptr;
    node* currentNode;
    while (list != nullptr) {
        currentNode = list;
        list = currentNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
    }
    list = currentNode;
}

int main() {
    list list1 = nullptr;
    insertAtRear(list1, 3);
    insertAtRear(list1, 5);
    insertAtRear(list1, 4);
    insertAtRear(list1, 9);
    
    printList(list1);
    
    node* nodeInfo5 = search(list1, 5);

    //Delete the node after the one with info = 5
    deleteAfter(nodeInfo5);
    //Insert a node with info = 10 after the node with info = 5    
    insertAfter(nodeInfo5, 10);

    printList(list1);

    list list2 = nullptr;
    insertAtRear(list2, 25);
    insertAtRear(list2, 34);

    concat(list1, list2);

    printList(list1);
    printList(list2);

    reverseList(list1);
    printList(list1);
    printList(list2); // because we used concate(list1, list2), reverseList(list1) affects list 2
}