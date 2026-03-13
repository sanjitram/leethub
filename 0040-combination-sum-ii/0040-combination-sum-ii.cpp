class Solution {
public:
    void dfs(vector<vector<int>>& v,vector<int>& curr,int i,vector<int>& num,int target){
        if(target==0){
            v.push_back(curr);
            return;
        }
        if(i==51 || target<0)    return;
        if(num[i]>0){
            curr.push_back(i);
            num[i]--;
            dfs(v,curr,i,num,target-i);
            curr.pop_back();
            num[i]++;
            dfs(v,curr,i+1,num,target);
        }
        else{
            dfs(v,curr,i+1,num,target);
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        vector<vector<int>> v;
        int i=0;
        vector<int> num(51,0);
        for(int i:candidates)   num[i]++;
        
        dfs(v,curr,i,num,target);
        return v;
    }
};