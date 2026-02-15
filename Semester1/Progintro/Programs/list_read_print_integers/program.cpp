#include <cstdio>
using namespace std;

struct node {
    int num;
    node* next;
};

typedef node* nodeptr;

//Creates a singly linked list of integer inputs
//The list stores the values in reverse order of input
//Returns a pointer to the head of the list
nodeptr read_int_reversed () {  
    nodeptr head = nullptr, current_node;

    int read_num;
    while (scanf("%d", &read_num) != EOF) {
        current_node = new node;
        current_node->num = read_num;
        current_node->next = head;

        head = current_node;
    }
    return head;
}

// Prints the list in the original input order
// (by traversing recursively to the end first)
// Deletes all nodes after printing
void print_delete_list_in_order_given (nodeptr head) { 
    if (head == nullptr) return;

    print_delete_list_in_order_given(head->next);
    printf("%d\n", head->num);
    delete head;
}

int main() {
    nodeptr head = read_int_reversed();

    if (head == nullptr) {
        printf("No numbers where given\n");
    } else {
        print_delete_list_in_order_given(head);
    }    
        
    return 0;
}