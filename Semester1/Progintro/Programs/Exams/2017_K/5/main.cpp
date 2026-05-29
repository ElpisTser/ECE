#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

int unbalanceHelp(Node* t, int& maxUnb) {
    if (t == nullptr)
        return -1;

    int heightLeft = unbalanceHelp(t->left, maxUnb);
    int heightRight = unbalanceHelp(t->right, maxUnb);

    int unb = (heightLeft > heightRight) ? heightLeft - heightRight : heightRight - heightLeft;
    if (unb > maxUnb)
        maxUnb = unb;

    return ((heightLeft > heightRight) ? heightLeft : heightRight) + 1 ;

}

int unbalance(Node* t) {
    int maxUnb = 0;
    unbalanceHelp(t, maxUnb);
    return maxUnb;
}