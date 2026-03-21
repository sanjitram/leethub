class Solution {
public:
    bool search(vector<int>& q,vector<int>& fr,int n){
        int mfr=0;
        int pick=-1;
        for(int i=0;i<26;i++){
            if(q[i]==0 && mfr<fr[i]){
                mfr=fr[i];
                pick=i;
            }
            q[i]=max(0,q[i]-1);
        }
        int fl=0;
        for(int i=0;i<26;i++){
            if(fr[i]>0)
                fl=1;
        }
        if(fl==0)
            return false;
        if(pick!=-1){
        q[pick]=n;
        fr[pick]--;}
        return true;
        
    }
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> q(26,0),fr(26,0);
        for(char c:tasks){
            fr[c-'A']++;
        }
        bool f=true;
        int c=0;
        while(f){
            f=search(q,fr,n);
            c++;
        }
        return c-1;
    }
};