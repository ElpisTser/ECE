#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    int height;
};

Node* newNode(int data) {
    Node* n = new Node;
    n->data = data;
    n->right = n->left = nullptr;
    n->height = 1;

    return n;
}

int height(Node* n) {
    if (n == nullptr) return 0;
    return n->height;
}


Node* rotateRight(Node* root) {
    Node* newRoot = root->left;
    Node* temp = newRoot->right;

    newRoot->right = root;
    root->left = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
}

Node* rotateLeft(Node* root) {
    Node* newRoot = root->right;
    Node* temp  = newRoot->left;

    newRoot->left = root;
    root->right = temp;

    root->height = max(height(root->left), height(root->right)) + 1;
    newRoot->height = max(height(newRoot->left), height(newRoot->right)) + 1;

    return newRoot;
};

int getBalance(Node* n) {
    if (n==nullptr) return 0;
    return height(n->left) - height(n->right);
}

Node* rebalanceNode(Node* n) {
    n->height = 1 + max(height(n->left), height(n->right));

    int balance = getBalance(n);
    if (balance > 1) {
        if (getBalance(n->left) >= 0) 
            return rotateRight(n);

        n->left = rotateLeft(n->left);
        return rotateRight(n);
    } else if (balance < -1) {
        if (getBalance(n->right) <= 0)
            return rotateLeft(n);

        n->right = rotateRight(n->right);
        return rotateLeft(n);    
    }

    return n;
}

Node* insertNode(Node* n, int k) {
    if (n == nullptr)
        return newNode(k);

    if(k < n->data)
        n->left = insertNode(n->left, k);
    else if(k > n->data)
        n->right = insertNode(n->right, k);
    else
        return n;

    return rebalanceNode(n);
}

Node* minValueNode(Node* n) {
    while (n->left != nullptr)
        n = n->left;
    return n;
}

Node* deleteNode(Node* n, int k) {
    if (n == nullptr) return n;

    if (k < n->data)
        n->left = deleteNode(n->left, k);
    else if (k > n->data)
        n->right = deleteNode(n->right, k);
    else {
        Node* temp = n;
        if (n->left == nullptr && n->right == nullptr) {
            n = nullptr;
            delete temp;
        } else if (n->left == nullptr) {
            n = n->right;
            delete temp;
        } else if (n->right == nullptr) {
            n = n->left;
            delete temp;
        } else {
            temp = minValueNode(n->right);
            n->data = temp->data;

            deleteNode(n->right, temp->data);
        }
    }

    if (n == nullptr) return n;

    return rebalanceNode(n);
}

void printInOrder(Node* n) {
    if (n == nullptr) return;
    printInOrder(n->left);
    cout << n->data << " ";
    printInOrder(n->right);
}

int main() {

    Node * tree = nullptr;

    tree = insertNode(tree, 5);

    tree = insertNode(tree, 4);

    tree = insertNode(tree, 8);

    tree = insertNode(tree, 2);

    tree = insertNode(tree, 3);

    tree = insertNode(tree, 1);

    tree = insertNode(tree, 6);

    tree = deleteNode(tree, 5);

    printInOrder(tree);
}
