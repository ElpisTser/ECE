struct node_int {
    int data;
    node_int* next;
};

struct node_real {
    double data;
    node_real* next;
};

struct node_both {
    int int_data;
    double real_data;
    node_both* next;
};

node_both* zip(node_int* p1, node_real* p2) {
    if(p1 == nullptr || p2 == nullptr) {
        return nullptr;
    }

    node_int* ip = p1;
    node_real* rp = p2;
    node_both* current_node = new node_both;
    node_both* list_start = current_node;

    while (true) {

        current_node->int_data = ip->data;
        current_node->real_data = rp->data;

        if (ip->next == nullptr || rp->next == nullptr) {
            current_node->next = nullptr;
            break;
        }

        node_both* next_node = new node_both;
        current_node->next = next_node;
        current_node = next_node;

        ip = ip->next;
        rp = rp->next;
    }

    return list_start;
}