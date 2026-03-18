class Solution {
public:
    bool dfs(string& s1,string& s2,string& s3,int a,int b,int c,vector<vector<int>>& dp){
        bool b1=false,b2=false;
        if(c==s3.size() && a==s1.size() && b==s2.size())    return true;
        if(c==s3.size())    return false;
        if(dp[a][b]!=-1)    return (dp[a][b]==1);
        if(s1[a]==s3[c]){
            b1=dfs(s1,s2,s3,a+1,b,c+1,dp);
        }
        if(s2[b]==s3[c]){
            b2=dfs(s1,s2,s3,a,b+1,c+1,dp);
        }
        return  dp[a][b]=b1||b2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        return dfs(s1,s2,s3,0,0,0,dp);
    }
};