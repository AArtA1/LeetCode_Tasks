#include <iostream>
#include <unordered_map>
#include <vector>

using std::unordered_map, std::vector,std::string;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};



string traversal(TreeNode *root,vector<TreeNode*>& res, unordered_map<string, int>& map){
    if(root == nullptr){
        return "";
    }
    string s = std::to_string(root->val) + "," + traversal(root->left,res,map) + "," + traversal(root->right,res,map);
    if(map[s]++ == 1){
        res.push_back(root);
    };
    return s;
}


// Time Complexity:O(n)
// Space Complexity: O(n)
vector<TreeNode *> findDuplicateSubtrees(TreeNode *root) {
    unordered_map<string,int> map;
    vector<TreeNode*> res;
    traversal(root,res,map);
    return res;
}


int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(2);
    root->right->right = new TreeNode(4);
    root->right->left->left = new TreeNode(4);
    findDuplicateSubtrees(root);
}
