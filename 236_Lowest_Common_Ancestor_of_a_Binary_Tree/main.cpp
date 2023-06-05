#include <iostream>
#include <vector>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool find(TreeNode* root,TreeNode* value,std::vector<TreeNode*>& arr){
    if(root == nullptr){
        return false;
    }
    if(root == value){
        arr.push_back(value);
        return true;
    }
    bool res1 = find(root->left,value,arr);
    if(res1){
        arr.push_back(root);
        return true;
    }
    bool res2 = find(root->right,value,arr);
    if(res2){
        arr.push_back(root);
        return true;
    }
    return false;
}

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::vector<TreeNode*> first,second;
    find(root,p,first);
    find(root,q,second);
    std::reverse(first.begin(),first.end());
    std::reverse(second.begin(),second.end());
    auto first_length = first.size()-1;
    auto second_length = second.size()-1;
    first_length = std::min(first_length,second_length);
    second_length = std::min(first_length,second_length);
    if(first[first_length] == second[second_length]){
        return first[first_length];
    }
    while(first[first_length - 1] != second[second_length-1]){
        --first_length;
        --second_length;
    }
    return first[first_length-1];
}



int main() {
    auto x = new TreeNode(3);
    x->left = new TreeNode(5);
    x->right = new TreeNode(1);
    x->left->left = new TreeNode(6);
    x->left->right = new TreeNode(2);
    x->left->right->left = new TreeNode(7);
    x->left->right->right = new TreeNode(4);
    x->right->left = new TreeNode(0);
    x->right->right = new TreeNode(8);
    auto result = lowestCommonAncestor(x,x->left,x->left->right->right);

}
