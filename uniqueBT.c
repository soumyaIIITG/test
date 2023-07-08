#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to find the index of an element in a given array
int findIndex(int arr[], int start, int end, int value) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr[i] == value)
            return i;
    }
    return -1;
}

// Function to build the tree from inorder and postorder arrays
struct Node* buildTree(int inorder[], int postorder[], int inStart, int inEnd, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    // Create a new Node with the current postorder element
    struct Node* node = createNode(postorder[*postIndex]);
    (*postIndex)--;

    // If the node has no children, return the node
    if (inStart == inEnd)
        return node;

    // Find the index of the current node in the inorder array
    int inIndex = findIndex(inorder, inStart, inEnd, node->data);

    // Recursively build the right subtree
    node->right = buildTree(inorder, postorder, inIndex + 1, inEnd, postIndex);

    // Recursively build the left subtree
    node->left = buildTree(inorder, postorder, inStart, inIndex - 1, postIndex);

    return node;
}

// Function to print the tree structure
void printTree(struct Node* node, int space) {
    if (node == NULL)
        return;

    // Increase distance between levels
    space += 4;

    // Process right child first
    printTree(node->right, space);

    // Print current node after space
    printf("\n");
    for (int i = 4; i < space; i++)
        printf(" ");
    printf("%d\n", node->data);

    // Process left child
    printTree(node->left, space);
}

// Function to free the memory allocated for the tree
void freeTree(struct Node* node) {
    if (node == NULL)
        return;

    freeTree(node->left);
    freeTree(node->right);
    free(node);
}

// Main function
int main() {
    int inorder[] =   {1,6,2,5,7,3};
    int postorder[] = {1,2,6,3,7,5};
    int len = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = len - 1;

    // Build the tree
    struct Node* root = buildTree(inorder, postorder, 0, len - 1, &postIndex);

    // Print the tree structure
    printf("Tree Structure:\n");
    printTree(root, 0);
    printf("\n");

    // Free the memory allocated for the tree
    freeTree(root);

    return 0;
}
