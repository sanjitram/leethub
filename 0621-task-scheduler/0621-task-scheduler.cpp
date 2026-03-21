class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> m;
        for(char c:tasks){
            m[c]++;
        }
        int ma=INT_MIN;
        for(auto &[k,v]:m){
            ma=max(v,ma);
        }
        int c=0;
        for(auto &[k,v]:m){
            if(v==ma)
                c++;
        }
        return max((int)tasks.size(),((ma-1)*(n+1)+c));
    }
};