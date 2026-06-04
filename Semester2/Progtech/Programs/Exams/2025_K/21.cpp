#include <iostream>
using namespace std;

enum state {LH, RH, EH};

struct Node {
    int data;
    state s;
    int weight;
    Node* left;
    Node* right;
};

struct  Values {
    int height;
    int nodes;
    Values(int h, int n) : height(h), nodes(n) {}
};

Values validateHelp(Node* t, bool& valid) {
    if (t == nullptr || !valid) {
        return Values(-1, 0);
    }

    Values leftValues = validateHelp(t->left, valid);
    Values rightValues = validateHelp(t->right, valid);

    int height = ((leftValues.height > rightValues.height) ? leftValues.height : rightValues.height) + 1;
    int nodes = leftValues.nodes + rightValues.nodes + 1;

    switch (t->s) {
        case LH:
            if (!(leftValues.height > rightValues.height)) {
                valid = false;
            }
            break;
        case RH:
            if (!(rightValues.height > leftValues.height)) {
                valid = false;
            }
            break;
        case EH:
            if (!(leftValues.height == rightValues.height)) {
                valid = false;
            }
    }   

    if (t->weight != nodes)
        valid = false;

    return Values(height, nodes);
}

bool validate(Node* tree) {
    if (tree == nullptr)
        return true;
    bool valid = true;
    validateHelp(tree, valid);
    return valid;
}
