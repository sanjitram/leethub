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
class Solution {
public:
    bool com(TreeNode* l,TreeNode* r){
        if(l==nullptr && r==nullptr)    return true;
        if((l==nullptr && r!=nullptr) || (l!=nullptr && r==nullptr) || (l->val!=r->val))  return false;
        
        return (com(l->left,r->right) && com(l->right,r->left));
    }
    bool isSymmetric(TreeNode* root) {
        return com(root,root);
    }
};