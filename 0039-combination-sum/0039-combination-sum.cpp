class Solution {
public:
    void dfs(vector<vector<int>>& v,int i,vector<int>& candidates,int target,vector<int>& curr){
        
        if(target==0){
            v.push_back(curr);
            return;
        }
        if(i==candidates.size() || target<0){
            return;
        }
        curr.push_back(candidates[i]);
        dfs(v,i,candidates,target-candidates[i],curr);
        curr.pop_back();
        dfs(v,i+1,candidates,target,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> v;
        int i=0;
        vector<int> curr;
        dfs(v,i,candidates,target,curr);
        return v;
    }
};