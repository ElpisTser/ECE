#include <iostream>
#include <string>
#include "lexicon.hpp"

using namespace std;

lexicon::lexicon() : root(nullptr) {}

void lexicon::deleteTree(Node* node) {
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

lexicon::~lexicon() {
    deleteTree(root);
}


void lexicon::insert(const string & s) {
    if (root == nullptr) {
        root = new Node(s, 1, nullptr, nullptr);
        return;
    }

    Node* node = root;

    while (node != nullptr) {
        if ((node->word).compare(s) == 0) {
            ++(node->freq);
            return;
        }
        else if ((node->word).compare(s) < 0) {
            // node->word is alphabetically smaller, go RIGHT
            if (node->right == nullptr) {
                node->right = new Node(s, 1, nullptr, nullptr);
                return;
            }
            node = node->right;
        }
        else {
            // node->word is alphabetically larger, go LEFT
            if (node->left == nullptr) {
                node->left = new Node(s, 1, nullptr, nullptr);
                return;
            }
            node = node->left;
        }
    }

    node = new Node(s, 1, nullptr, nullptr);
}

void lexicon::printHelp(Node* node, ostream& out) {
    if (node == nullptr)
        return;

    printHelp(node->left, out);
    out << node->word << " " << node->freq << endl;
    printHelp(node->right, out);
}

ostream & operator <<(ostream& out, const lexicon& l) {
    lexicon::printHelp(l.root, out);
    return out;
}