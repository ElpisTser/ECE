#include <cstdio>
using namespace std;

struct node {
    int info;
    node* left;
    node* right;
};

class bstree {
public:
    bstree();
    void insert(int data);
    void print();
private:
    node* root;
};

bstree::bstree() {
    root = nullptr;
}

node* insert_aux(node* tree, int data);
void print_aux(node* tree);

void bstree::insert(int data) {
    root = insert_aux(root, data);
}

void bstree::print() {
    printf("Tree contents: ");
    print_aux(root);
    printf("\n");
}

node* insert_aux(node* tree, int data) {
    if (tree == nullptr) {
        node* p = new node;
        p->info = data;
        p->left = p->right = nullptr;
        return p;
    }
    if (data < tree->info) {
        tree->left = insert_aux(tree->left, data);
    } else if (data > tree->info) {
        tree->right = insert_aux(tree->right, data);
    }
    return tree;
}

void print_aux(node* tree) { //inorder print
    if (tree != nullptr) {
        print_aux(tree->left);
        printf("%d ", tree->info);
        print_aux(tree->right);
    }
}

int main() {
    bstree root;

    for (int i=0; i<10; i++) {
        int data;
        scanf("%d", &data);
        printf("After inserting data %d \n", data);
        root.insert(data);
        root.print();
    }
}