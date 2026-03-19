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
    TreeNode* dfs(int& i,map<int,int>& ind,int left,int right,vector<int>& preorder){
        if(left>right)  return nullptr;
        TreeNode* root=new TreeNode(preorder[i]);
        int in=ind[preorder[i]];
        i++;
        root->left=dfs(i,ind,left,in-1,preorder);
        root->right=dfs(i,ind,in+1,right,preorder);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> ind;
        for(int i=0;i<inorder.size();i++){
            ind[inorder[i]]=i;
        }
        int left=0,right=inorder.size()-1;
        int i=0;
        return dfs(i,ind,left,right,preorder);
    }
};