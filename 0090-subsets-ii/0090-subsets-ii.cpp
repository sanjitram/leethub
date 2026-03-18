class Solution {
public:
    void dfs(vector<int>& nums,set<vector<int>>& ans,int i,vector<int>& cur){
        if(i==nums.size())
        {ans.insert(cur);return;}

        cur.push_back(nums[i]);
        dfs(nums,ans,i+1,cur);

        cur.pop_back();
        dfs(nums,ans,i+1,cur);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        set<vector<int>> ans;
        vector<int> cur;
        dfs(nums,ans,0,cur);
        vector<vector<int>> v;
        for(auto &s:ans)
            v.push_back(s);
        return v;
    }
};