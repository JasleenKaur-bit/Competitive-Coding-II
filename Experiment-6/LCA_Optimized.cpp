#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Node structure for a Binary Tree
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
// Build binary tree from level-order input
// -1 represents NULL.
TreeNode* buildTree(vector<int>& values) {
    if (values.empty() || values[0] == -1)
        return nullptr;
    TreeNode* root = new TreeNode(values[0]);
    queue<TreeNode*> q;
    q.push(root);
    int index = 1;
    while (!q.empty() && index < values.size()) {
        TreeNode* current = q.front();
        q.pop();
        // Create left child
        if (index < values.size() && values[index] != -1) {
            current->left = new TreeNode(values[index]);
            q.push(current->left);
        }
        index++;
        // Create right child
        if (index < values.size() && values[index] != -1) {
            current->right = new TreeNode(values[index]);
            q.push(current->right);
        }
        index++;
    }
    return root;
}
// Optimized LCA using one DFS traversal
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    // Base condition:
    // If tree is empty or current node is p/q,
    // return the current node.
    if (root == nullptr ||
        root->data == p ||
        root->data == q) {
        return root;
    }
    // Search in left subtree
    TreeNode* leftResult =
        lowestCommonAncestor(root->left, p, q);
    // Search in right subtree
    TreeNode* rightResult =
        lowestCommonAncestor(root->right, p, q);
    // If both sides contain one target,
    // current node is the LCA.
    if (leftResult != nullptr &&
        rightResult != nullptr) {
        return root;
    }
    // If only one side contains a target,
    // return that result.
    if (leftResult != nullptr)
        return leftResult;
    return rightResult;
}
int main() {
    int n;
    cout << "===== Lowest Common Ancestor - Optimized DFS =====\n\n";
    cout << "Enter number of input positions: ";
    cin >> n;
    vector<int> values(n);
    cout << "Enter level-order elements (-1 for NULL):\n";
    for (int i = 0; i < n; i++) {
        cin >> values[i];
    }
    TreeNode* root = buildTree(values);
    int p, q;
    cout << "Enter first node (p): ";
    cin >> p;
    cout << "Enter second node (q): ";
    cin >> q;
    TreeNode* answer =
        lowestCommonAncestor(root, p, q);
    if (answer != nullptr)
        cout << "\nLowest Common Ancestor of "
             << p << " and " << q
             << " = " << answer->data << endl;
    else
        cout << "\nLCA not found." << endl;
    return 0;
}