class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        vector<int> v(n);
        int s=0;
        for(int i=0;i<n;i++){
            v[i]=gas[i]-cost[i];
            s+=v[i];
        }
        if(s<0) return -1;
        int c=0;
        int st=0;
        for(int i=0;i<n;i++){
            c+=v[i];
            if(c<0){
                c=0;
                st=i+1;
            }
        }
        return st;
        
        
    }
};