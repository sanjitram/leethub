class Solution {
public:
    int dfs(string& s,int i,vector<int>& dp){
        if(i>=s.size()) return 1;
        if(s[i]=='0')   return 0;
        if(dp[i]!=-1)   return dp[i];
        int a=0,b=0;
        if((s[i]=='1' && i<s.size()-1) || (s[i]=='2' && (i<s.size()-1 && s[i+1]<'7'))){
            a=dfs(s,i+2,dp);
        }
        b=dfs(s,i+1,dp);
        return dp[i]=a+b;
    }
    int numDecodings(string s) {
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                if(i==0 || s[i-1]=='0' || s[i-1]>'2'){
                    return 0;
                }
            }
        }
        vector<int> dp(s.size()+1,-1);
        return dfs(s,0,dp);
    }
};