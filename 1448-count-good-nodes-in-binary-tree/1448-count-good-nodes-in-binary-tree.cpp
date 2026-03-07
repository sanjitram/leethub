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
    void dfs(TreeNode* root,int ma,int& c){
        if(root==nullptr)   return;
        if(root->val>=ma){
            c++;
            dfs(root->left,root->val,c);dfs(root->right,root->val,c);}
        else{
            dfs(root->left,ma,c);dfs(root->right,ma,c);}
        
    }
    int goodNodes(TreeNode* root) {
        int c=0;
        dfs(root,root->val,c);
        return c;
    }
};