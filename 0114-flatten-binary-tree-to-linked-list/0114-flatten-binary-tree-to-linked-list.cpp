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
    void pre(TreeNode* root,vector<int>& v){
        if(root==nullptr)   return;
        v.push_back(root->val);
        pre(root->left,v);
        pre(root->right,v);
    }
    void flatten(TreeNode* root) {
        vector<int> v;
        pre(root,v);
        TreeNode* r=root;
        for(int i=1;i<v.size();i++){
            r->left=nullptr;
            r->right=new TreeNode(v[i]);
            r=r->right;
        }
        
    }
};