class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size()) return false;
        vector<int> hs(26,-1);
        for(char c:s1){
            hs[c-'a']++;
        }
        vector<int> h(26,-1);
        for(int i=0;i<s1.size();i++){
            h[s2[i]-'a']++;
        }
        if(h==hs)   return true;
        int l=0,r=s1.size()-1;
        while(r<s2.size()-1){
            l++;r++;
            h[s2[l-1]-'a']--;h[s2[r]-'a']++;
            if(h==hs)   return true;
        }
        return false;
    }
};