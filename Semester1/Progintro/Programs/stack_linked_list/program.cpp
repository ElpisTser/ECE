#include <cstdio>
using namespace std;

class Stack {
public:
    Stack();
    bool empty();
    void push(int i);
    int pop();
    int getLast();
private:
    struct node {
        int info;
        node* next;
    };
    typedef node* nodeptr;

    nodeptr head;
};

Stack :: Stack() {
    head = nullptr;
}

bool Stack:: empty() {
    return (head==nullptr);
}

void Stack :: push(int i) {
    nodeptr n = new node;
    n->info = i;
    n->next = head;
    head = n;
}

int Stack :: pop() {
    int i = head->info;
    nodeptr n = head;
    head = head->next;
    delete n;
    return i;
}

int Stack :: getLast() {
    return head->info;
}

int main() {
    Stack s;

    for (int i=1; i<=10; i++) {
        s.push(i);
    }

    while (!s.empty()) {
        printf("%d\n", s.pop());
    }

    if (s.empty()) s.push(4);

    printf("%d\n", s.getLast());
}