class Solution {
public:
    void dfs(vector<int>& nums,vector<vector<int>>& ans,int i,vector<int>& cur){
        ans.push_back(cur);
        for(int j=i;j<nums.size();j++){
            cur.push_back(nums[j]);
            dfs(nums,ans,j+1,cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        dfs(nums,ans,0,cur);
        return ans;
    }
};