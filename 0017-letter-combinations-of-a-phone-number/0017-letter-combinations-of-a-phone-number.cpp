class Solution {
public:
    
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        vector<string> v={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans={""};
        for(char c:digits){
            vector<string> na;
            int d=c-'0';
            string s=v[d-2];
            for(string st:ans){
                for(char ch:s){
                    na.push_back(st+ch);
                }
            }
            ans=na;
        }
        return ans;

    }
};