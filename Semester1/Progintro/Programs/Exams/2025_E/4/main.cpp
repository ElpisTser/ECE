#include <cstdio>

// ============================================================================
// NODE STRUCTURE
// ============================================================================
// Represents a single node in the binary tree
struct Node {
    int data;       // The value stored in this node
    Node* left;     // Pointer to left child (NULL if no left child)
    Node* right;    // Pointer to right child (NULL if no right child)
};

// ============================================================================
// HELPER FUNCTION: Calculate sum AND height in one O(n) traversal
// ============================================================================
// Parameters:
//   - node: current node being processed
//   - depth: distance from root to this node (root has depth 0)
//   - sum: pointer to accumulate the sum (modified by reference)
//
// Returns:
//   - Height of the subtree rooted at this node
//   - IMPORTANT: Returns -1 for NULL nodes (base case)
//   - Leaf nodes return 0
//
// Key idea: This function does TWO things:
//   1. Calculates the height of the current node
//   2. Checks if depth <= height and adds to sum if true
//   3. Then returns the height for the PARENT to use
// ============================================================================
int sumQualifyingNodesHelper(Node* node, int depth, int& sum) {
    // BASE CASE: If node is NULL, return -1
    // Why -1? Because when we calculate height = 1 + max(leftH, rightH)
    // a leaf node with two NULL children becomes: 1 + max(-1, -1) = 0 ✓
    if (node == NULL) {
        return -1;
    }
    
    // RECURSIVE CALLS: Get heights of children
    // IMPORTANT: Pass depth+1 (NOT depth++) to children!
    // depth++ is post-increment (increments AFTER use) - wrong here
    // depth+1 gives the correct depth to the child before the call
    int leftHeight = sumQualifyingNodesHelper(node->left, depth + 1, sum) + 1;
    int rightHeight = sumQualifyingNodesHelper(node->right, depth + 1, sum) + 1;
    
    // CALCULATE THIS NODE'S HEIGHT
    // Height = 1 + max(left height, right height)
    // We add 1 because we need to count this node in the path
    int nodeHeight = (leftHeight > rightHeight) ? leftHeight : rightHeight;
    
    // CHECK THE CONDITION: Does this node qualify?
    // If depth <= height, add its data to the sum
    if (depth <= nodeHeight) {
        sum += node->data;
    }
    
    // RETURN HEIGHT to parent
    // The parent will use this value to calculate its own height
    // This is how information flows UP the tree
    return nodeHeight;
}

// ============================================================================
// WRAPPER FUNCTION: User-facing function
// ============================================================================
// This function initializes the sum and calls the helper
// Returns the final sum of all qualifying nodes
int sumQualifyingNodes(Node* root) {
    int sum = 0;
    
    // Call helper starting from root with depth 0
    // The return value (root's height) is not used, but it's part of the recursion
    sumQualifyingNodesHelper(root, 0, sum);
    
    // Return the accumulated sum (NOT the height!)
    // IMPORTANT: This was a bug in your code - you returned result (height)
    // instead of sum
    return sum;
}

// ============================================================================
// HELPER FUNCTION: Create a new node
// ============================================================================
Node* createNode(int data) {
    Node* newNode = new Node(); 
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ============================================================================
// MAIN: Test the implementation
// ============================================================================
int main() {
    printf("=== Binary Tree: Sum of nodes where depth <= height ===\n\n");
    
    // Build test tree:
    //        10        (d=0, h=2)
    //       /  \
    //      5    8     (d=1, h=1 and h=0)
    //     / \
    //    3   7        (d=2, h=0 and h=0)
    
    printf("Tree structure:\n");
    printf("        10\n");
    printf("       /  \\\n");
    printf("      5    8\n");
    printf("     / \\\n");
    printf("    3   7\n\n");
    
    Node* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(8);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    
    // Calculate the sum
    int result = sumQualifyingNodes(root);
    
    printf("Node analysis:\n");
    printf("Node 10: depth=0, height=2 -> 0 <= 2 ? YES  -> (add 10)\n");
    printf("Node 5:  depth=1, height=1 -> 1 <= 1 ? YES  -> (add 5)\n");
    printf("Node 8:  depth=1, height=0 -> 1 <= 0 ? NO   -> (skip)\n");
    printf("Node 3:  depth=2, height=0 -> 2 <= 0 ? NO   -> (skip)\n");
    printf("Node 7:  depth=2, height=0 -> 2 <= 0 ? NO   -> (skip)\n\n");
    
    printf("Sum of qualifying nodes: 10 + 5 = %d\n", result);
    printf("\nComplexity: O(n) - each node visited exactly once\n");
    
    return 0;
}