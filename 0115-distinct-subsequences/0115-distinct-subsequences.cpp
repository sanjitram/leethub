class Solution {
public:
    int dfs(string& s,string& t,vector<vector<int>>& dp,int i,int j){
        if(i==0){
            return 1;
        }
        if(j==0){
            return 0;
        }
        if(dp[i][j]!=-1)    return dp[i][j];
        if(t[i-1]==s[j-1])
            return dp[i][j]=dfs(s,t,dp,i,j-1)+dfs(s,t,dp,i-1,j-1);
        return dp[i][j]=dfs(s,t,dp,i,j-1);
    }
    int numDistinct(string s, string t) {
        vector<vector<int>> dp(t.size()+1,vector<int> (s.size()+1,-1));
        return dfs(s,t,dp,t.size(),s.size());
    }
};