#include <iostream>

using namespace std;

struct TreeNode {
    char type; // 'n' for number, '+' for addition, '*' for multiplication, etc.
    int value; // Value if the node is a number
    TreeNode* left = nullptr;
    TreeNode* right = nullptr;

    TreeNode(char t, int v) : type(t), value(v) {}
};

int evaluate(TreeNode* root) {
    if (!root)
        return 0;

    if (root->type == 'n')
        return root->value;

    int l_val = evaluate(root->left);
    int r_val = evaluate(root->right);

    if (root->type == '+')
        return l_val + r_val;
    if (root->type == '*')
        return l_val * r_val;

    // Handle other operators if needed

    return 0; // Invalid operator
}

int main() {
    // Example expression tree: 1 + ((3 + 5) * 2)
    TreeNode* root = new TreeNode('+', 0);
    root->left = new TreeNode('n', 1);
    root->right = new TreeNode('*', 0);
    root->right->left = new TreeNode('+', 0);
    root->right->left->left = new TreeNode('n', 3);
    root->right->left->right = new TreeNode('n', 5);
    root->right->right = new TreeNode('n', 2);

    cout << "Result: " << evaluate(root) << endl;

    // Clean up memory
    delete root;
    return 0;
}