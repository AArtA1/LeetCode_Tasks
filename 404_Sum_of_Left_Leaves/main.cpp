#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void find(TreeNode* node, int& sum){
    if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr){
        sum += node->left->val;
    }

    if(node->left != nullptr){
        find(node->left,sum);
    }
    if(node->right != nullptr){
        find(node->right,sum);
    }
}


int sumOfLeftLeaves(TreeNode *root) {
    int sum = 0;
    find(root,sum);
    return sum;
}

int main() {
    TreeNode* x = new TreeNode(3);
    x->left = new TreeNode(9);
    x->right = new TreeNode(20);
    x->right->left = new TreeNode(15);
    x->right->right = new TreeNode(7);
    sumOfLeftLeaves(x);
}
