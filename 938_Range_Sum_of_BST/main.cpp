#include <iostream>

struct TreeNode {
         int val;
         TreeNode *left;
         TreeNode *right;
         TreeNode() : val(0), left(nullptr), right(nullptr) {}
         TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
         TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };


void traversal(TreeNode *root,int low,int high,int& sum){
    if(root == nullptr){
        return;
    }

    if(root->val >= low && root->val <= high){
        sum += root->val;
    }

    traversal(root->left,low,high,sum);
    traversal(root->right,low,high,sum);
}


int rangeSumBST(TreeNode* root, int low, int high) {
    int sum = 0;
    traversal(root,low,high,sum);
    return sum;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
