class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>>& ans,int i,vector<int>& cur){
        if(i==nums.size())
        {ans.push_back(cur);return;}

        cur.push_back(nums[i]);
        dfs(nums,ans,i+1,cur);

        cur.pop_back();
        dfs(nums,ans,i+1,cur);
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums,ans,0,cur);
        return ans;
    }
};