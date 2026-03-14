class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> ph(n),sh(n);
        int mh=0;
        for(int i=0;i<n;i++){
            mh=max(mh,height[i]);
            ph[i]=mh;
        }
        mh=0;
        for(int i=n-1;i>=0;i--){
            mh=max(mh,height[i]);
            sh[i]=mh;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max((min(sh[i],ph[i])-height[i]),0);
        }
        return ans;
    }
};