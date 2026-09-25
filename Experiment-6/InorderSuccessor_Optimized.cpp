#include <iostream>
using namespace std;
// Node structure for BST
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};
// Insert a value into BST
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr)
        return new TreeNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);
    return root;
}
// Optimized successor search using BST property
TreeNode* findSuccessor(TreeNode* root, int target) {
    TreeNode* successor = nullptr;
    // Traverse only one path from root
    while (root != nullptr) {
        // If target is greater than or equal to
        // current node, successor must be on right.
        if (target >= root->data) {
            root = root->right;
        }
        // Current node is greater than target.
        // Therefore it can be a possible successor.
        else {
            successor = root;
            // Try to find a smaller valid successor
            // in the left subtree.
            root = root->left;
        }
    }
    return successor;
}
int main() {
    cout << "===== Inorder Successor - Optimized BST =====\n\n";
    int n;
    cout << "Enter number of BST nodes: ";
    cin >> n;
    TreeNode* root = nullptr;
    cout << "Enter " << n << " distinct BST values:\n";
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }
    int target;
    cout << "Enter node value (p): ";
    cin >> target;
    TreeNode* successor =
        findSuccessor(root, target);
    if (successor != nullptr)
        cout << "\nInorder Successor of "
             << target << " = "
             << successor->data << endl;
    else
        cout << "\nInorder Successor of "
             << target << " = No successor" << endl;
    return 0;
}