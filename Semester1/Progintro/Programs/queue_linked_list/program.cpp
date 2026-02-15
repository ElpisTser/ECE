#include <cstdio>
using namespace std;

class Queue {
public:
    Queue();
    bool empty();
    void enqueue(int i);
    int dequeue();
    int getFront();
    int getRear();
private:
    struct node {
        int info;
        node* next;
    };
    typedef node* nodeptr;

    nodeptr front;
    nodeptr rear;
};

Queue::Queue() {
    front = rear = nullptr;
}

bool Queue::empty() {
    return front == nullptr;
}

void Queue::enqueue(int i) {
    nodeptr n = new node;
    n->info = i;
    n->next = nullptr;
    if (front == nullptr) 
        front = n;
    else
        rear->next = n;
    rear = n;    
}

int Queue::dequeue() {
    nodeptr n = front;
    int i = front->info;
    if (front == rear)
        rear = nullptr;
    front = front->next; 
    delete n;
    return i;
}

int Queue::getFront() {
    return front->info;
}

int Queue::getRear() {
    return rear->info;
}

int main() {
    Queue q;
    for (int i=1; i<=10; i++) {
        q.enqueue(i);
    }

    printf("First element: %d\n", q.getFront());
    printf("Last element: %d\n", q.getRear());

    printf("Empty Queue and print the elements in order:\n");
    while (!q.empty()) 
        printf("%d\n", q.dequeue());

    if (q.empty())
        printf("Queue is empty");
}