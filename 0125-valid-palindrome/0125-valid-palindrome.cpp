class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(char c:s){
            if(c<='Z' && c>='A')
                t+=c;
            else if(c<='z' && c>='a')
                t+=(c-32);
            else if(c<='9' && c>='0')
                t+=c;
        }
        int l=0,r=t.size()-1;
        while(l<r){
            if(t[l]!=t[r])
                return false;
            l++;r--;
        }
        return true;
    }
};