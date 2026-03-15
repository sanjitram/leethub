class Solution {
public:
    void dfs(vector<int>& cur,vector<vector<int>>& ans,vector<int>& nums,vector<bool>& u){
        if(cur.size()==nums.size()){
            ans.push_back(cur);
        }
        for(int i=0;i<nums.size();i++){
            if(u[i])    continue;
            u[i]=true;
            cur.push_back(nums[i]);
            dfs(cur,ans,nums,u);
            u[i]=false;
            cur.pop_back();

            
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> cur;
        vector<vector<int>> ans;
        vector<bool> u(nums.size(),false);
        dfs(cur,ans,nums,u);
        return ans;
    }
};