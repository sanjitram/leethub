class Solution {
public:
    int con(vector<int>& piles,int mid){
        int ans=0;
        for(int i=0;i<piles.size();i++){
            ans+=((piles[i]+mid-1)/mid);
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1,hi=1e9;
        while(lo<hi){
            int mid=(hi-lo)/2+lo;  
            if(con(piles,mid)<=h){
                hi=mid;
            }
            else
                lo=mid+1;
            
        }
        return hi;
    }
};