#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int find(TreeNode *value, TreeNode *root, std::vector<TreeNode*>& arr){
    auto current = root;
    int counter = 0;
    if(value == root){
        arr.push_back(current);
        return 0;
    }
    while(current != value && current != nullptr){
        arr.push_back(current);
        if(current->val > value->val){
            current = current->left;
        }
        else{
            current = current->right;
        }
        ++counter;
    }
    if(current == nullptr){
        return 0;
    }
    arr.push_back(current);
    return counter;
}



TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    std::vector<TreeNode*> first,second;
    auto first_length = find(p,root,first);
    auto second_length = find(q,root,second);
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
    /*TreeNode* x = new TreeNode(6);
    x->left = new TreeNode(2);
    x->right = new TreeNode(8);
    x->left->left = new TreeNode(0);
    x->left->right = new TreeNode(4);
    x->left->right->left = new TreeNode(3);
    x->left->right->right = new TreeNode(5);*/
    TreeNode* x = new TreeNode(2);
    x->left = new TreeNode(1);
    lowestCommonAncestor(x,x,x->left);
}
