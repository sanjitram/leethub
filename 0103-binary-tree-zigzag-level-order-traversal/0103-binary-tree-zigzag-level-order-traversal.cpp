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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==nullptr)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        int c=1;
        while(!q.empty()){
            vector<int> v;
            int s=q.size();
            c=1-c;
            for(int i=0;i<s;i++){
                TreeNode* d=q.front();q.pop();
                v.push_back(d->val);
                if(d->left!=nullptr)    q.push(d->left);
                if(d->right!=nullptr)   q.push(d->right);
            }
            if(c)   reverse(v.begin(),v.end());
            ans.push_back(v);
        }
        return ans;
        
        
    }
};