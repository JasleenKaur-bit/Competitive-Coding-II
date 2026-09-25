#include <iostream>
#include <vector>
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
// Insert a value into the BST
TreeNode* insertNode(TreeNode* root, int value) {
    if (root == nullptr)
        return new TreeNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else
        root->right = insertNode(root->right, value);
    return root;
}
// Complete inorder traversal
// In a BST, inorder gives sorted order.
void inorder(TreeNode* root, vector<TreeNode*>& order) {
    if (root == nullptr)
        return;
    inorder(root->left, order);
    order.push_back(root);
    inorder(root->right, order);
}
// Brute Force method
TreeNode* findSuccessor(TreeNode* root, int target) {
    vector<TreeNode*> order;
    // Store all nodes in inorder
    inorder(root, order);
    // Search for target
    for (int i = 0; i < order.size(); i++) {
        if (order[i]->data == target) {
            // If target is not the last node,
            // next node is the successor.
            if (i + 1 < order.size())
                return order[i + 1];
            // Target is the largest value.
            return nullptr;
        }
    }
    return nullptr;
}
int main() {
    cout << "===== Inorder Successor - Brute Force =====\n\n";
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