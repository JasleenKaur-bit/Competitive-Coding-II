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
// Build a binary tree using level-order input.
// Use -1 to represent a NULL node.
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
// Find the path from root to the target node
bool findPath(TreeNode* root, int target, vector<TreeNode*>& path) {
    if (root == nullptr)
        return false;
    path.push_back(root);
    // Target found
    if (root->data == target)
        return true;
    // Search left or right subtree
    if (findPath(root->left, target, path) ||
        findPath(root->right, target, path)) {
        return true;
    }
    // Backtrack if target was not found
    path.pop_back();
    return false;
}
// Brute Force LCA using two root-to-node paths
TreeNode* lowestCommonAncestor(TreeNode* root, int p, int q) {
    vector<TreeNode*> pathP;
    vector<TreeNode*> pathQ;
    // Find paths to both nodes
    findPath(root, p, pathP);
    findPath(root, q, pathQ);
    TreeNode* lca = nullptr;
    // Compare both paths
    int i = 0;
    while (i < pathP.size() &&
           i < pathQ.size() &&
           pathP[i]->data == pathQ[i]->data) {
        lca = pathP[i];
        i++;
    }
    return lca;
}
int main() {
    int n;
    cout << "===== Lowest Common Ancestor - Brute Force =====\n\n";
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
    TreeNode* answer = lowestCommonAncestor(root, p, q);
    if (answer != nullptr)
        cout << "\nLowest Common Ancestor of "
             << p << " and " << q
             << " = " << answer->data << endl;
    else
        cout << "\nLCA not found." << endl;
    return 0;
}