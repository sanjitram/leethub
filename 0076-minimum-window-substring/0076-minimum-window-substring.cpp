class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> tv(200,0),sv(200,0);
        for(char c:t){
            tv[c-'A']++;
        }
        int al=-1,ar=-1;
        int l=0,r=-1;
        int ml=INT_MAX;
        string st="";
        while(r<((int)s.size()-1)){
            r++;
            sv[s[r]-'A']++;
            int f=1;
            for(int i=0;i<200;i++){
                if(!(sv[i]>=tv[i]))
                    f=0;
            }
            while(f==1){
                ml=min(ml,r-l+1);
                
                if(ml==(r-l+1)){
                    al=l;ar=r;
                }
                    
                sv[s[l]-'A']--;
                l++;
                
                for(int i=0;i<200;i++){
                    if(!(sv[i]>=tv[i]))
                        f=0;
                }
            }
        }
        if(al==-1 && ar==-1)    return "";
        return s.substr(al,ar-al+1);
    }
};