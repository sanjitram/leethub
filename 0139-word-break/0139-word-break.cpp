class Solution {
public:
    bool found(string &cur, unordered_set<string>& dict){
        return dict.count(cur);
    }

    bool dfs(int i, string& s, unordered_set<string>& dict, string cur, vector<vector<int>>& dp){
        if(i == s.size()){
            return (cur == "" || found(cur, dict));
        }

        if(dp[i][cur.size()] != -1)
            return dp[i][cur.size()];

        bool a = false, b = false;

        // extend current substring
        string next = cur + s[i];

        // option 1: cut if valid
        if(found(next, dict)){
            a = dfs(i+1, s, dict, "", dp);
        }

        // option 2: continue building
        b = dfs(i+1, s, dict, next, dp);

        return dp[i][cur.size()] = (a || b);
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<vector<int>> dp(s.size()+1, vector<int>(s.size()+1, -1));
        return dfs(0, s, dict, "", dp);
    }
};