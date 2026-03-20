class Solution {
public:
    bool pal(string &s){
        int l = 0, r = s.size() - 1;
        while(l < r){
            if(s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }

    void dfs(int i, string &s, vector<vector<string>> &ans, vector<string> &cur){
        if(i == s.size()){
            // check all substrings are palindrome
            for(auto &str : cur){
                if(!pal(str)) return;
            }
            ans.push_back(cur);
            return;
        }

        // Option 1: start new substring
        string newStr = "";
        newStr += s[i];
        cur.push_back(newStr);
        dfs(i+1, s, ans, cur);
        cur.pop_back();

        // Option 2: extend last substring (only if exists)
        if(!cur.empty()){
            cur.back() += s[i];
            dfs(i+1, s, ans, cur);
            cur.back().pop_back(); // backtrack
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> cur;
        dfs(0, s, ans, cur);
        return ans;
    }
};