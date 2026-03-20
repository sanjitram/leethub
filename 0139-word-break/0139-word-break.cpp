class Solution {
public:
    bool found(string cur,vector<string>& wordDict){
        for(string s:wordDict){
            if(cur==s)
                return true;
        }
        return false;
    }
    bool dfs(int i,string& s,vector<string>& wordDict,string& cur,vector<vector<int>>& dp){
        if(i==s.size()){
            if(found(cur,wordDict) || cur=="")
                return true;
            else
                return false;
        }
        if(dp[i][cur.size()]!=-1){
            if(dp[i][cur.size()]==1)    return true;
            return false;
        }
        bool a=false,b=false;
        string t=cur+s[i];
        string em="";
        if(found(t,wordDict))
            a=dfs(i+1,s,wordDict,em,dp);
        b=dfs(i+1,s,wordDict,t,dp);
        if(a||b)
            dp[i][cur.size()]=1;
        else
            dp[i][cur.size()]=0;
        return a||b;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        string cur="";
        vector<vector<int>> dp(s.size()+1,vector<int> (s.size()+1,-1));
        return dfs(0,s,wordDict,cur,dp);
    }
};