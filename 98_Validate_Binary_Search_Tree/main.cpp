#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

bool isValidBST(TreeNode* root) {
    return traversal(root,INT32_MIN,INT32_MAX);
}

bool traversal(TreeNode* root,int min,int max){
    if(root == nullptr){
        return true;
    }
    if(root->val >= max || root->val <= min){
        return false;
    }
    return traversal(root->left,min,root->val) || traversal(root->right,root->val,max);
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
