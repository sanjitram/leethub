class Solution {
public:
    int con(string word1,string word2,vector<vector<int>>& dp,int i,int j){

        if(i<0)    return j+1;
        if(j<0)    return i+1;
        if(dp[i][j]!=-1)    return dp[i][j];
        if(word1[i]==word2[j]){
            return dp[i][j]=con(word1,word2,dp,i-1,j-1);
        }
        return dp[i][j]=1+min({con(word1,word2,dp,i-1,j-1),con(word1,word2,dp,i,j-1),con(word1,word2,dp,i-1,j)});
    }
    int minDistance(string word1, string word2) {
        if(word1.size()==0 || word2.size()==0)  return max(word1.size(),word2.size());
        vector<vector<int>> dp(word1.size()+1,vector<int> (word2.size()+1,-1));
        int i=word1.size()-1,j=word2.size()-1;
        return con(word1,word2,dp,i,j);
    }
};