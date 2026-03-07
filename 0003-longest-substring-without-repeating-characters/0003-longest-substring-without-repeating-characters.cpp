class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0) return 0;
        map<char,int> m;
        int l=0,r=0;
        int ml=1;
        m[s[l]]++;
        
        while(r<s.size()-1){
            r++;
            m[s[r]]++;
            if(m[s[r]]==2){
                while(s[l]!=s[r]){
                    m[s[l]]--;l++;
                }
                m[s[l]]--;
                l++;
            }
            ml=max(r-l+1,ml);
        }
        return ml;
    }
};