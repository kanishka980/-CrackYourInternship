class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
        {
            return 0;
        }
        int l=0;
        int h=n-1;
        while(l<h)
        {
            int m=l+(h-l)/2;
            if(nums[m]<nums[m+1])
            {
                l=m+1;
            }
            else
            {
                h=m;
            }
        }
        return l;
        
    }
};
