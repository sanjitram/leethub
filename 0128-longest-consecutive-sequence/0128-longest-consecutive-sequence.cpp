class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mc=0;
        int c=1;
        if(nums.size()==1)  return 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]==1)
                c++;
            else if(nums[i]-nums[i-1]>1)
                c=1;
            mc=max(mc,c);
        }
        return mc;

    }
};