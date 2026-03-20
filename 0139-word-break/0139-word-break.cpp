class Solution {
public:
    
    bool dfs(int i,string& s,unordered_set<string>& d,vector<int>& dp){
        if(i>=s.size()) return true;
        if(dp[i]!=-1)   return dp[i];
        string t="";
        for(int j=i;j<s.size();j++){
            t+=s[j];
            if(d.count(t) && dfs(j+1,s,d,dp)){
                return dp[i]=1;
            }
        }
        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> d(wordDict.begin(),wordDict.end());
        vector<int> dp(s.size()+1,-1);
        return dfs(0,s,d,dp);
    }
};