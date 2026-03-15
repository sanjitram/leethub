class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>,vector<string>> m;
        vector<vector<string>> ans;
        for(string s:strs){
            vector<int> h(26,0);
            for(char c:s){
                h[c-'a']++;
            }
            m[h].push_back(s);
        }
        for(auto [k,v]:m){
            ans.push_back(v);
        }
        return ans;
    }
};