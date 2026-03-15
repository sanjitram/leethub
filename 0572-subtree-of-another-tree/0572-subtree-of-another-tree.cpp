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
    bool same(TreeNode* s,TreeNode* r){
        if((s==nullptr && r!=nullptr) || (r==nullptr && s!=nullptr)){
            return false;
        }
        if(s==nullptr && r==nullptr){
            return true;
        }
        if(s->val==r->val){
            return (same(s->left,r->left) && same(s->right,r->right));
        }
        else
            return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==nullptr)   return false;
        if(same(root,subRoot))  return true;
        return (isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot));
    }
};