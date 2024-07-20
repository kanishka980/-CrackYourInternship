class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int stage=0;
        for(int i=0;i<n;i++)
        {
            if(stage<i)
            {
                return false;
            }
            stage=max(stage, i+nums[i]);

        }
        return true;
        
    }
};
