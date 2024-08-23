class Solution {
public:
    void helper(vector<vector<int>> &ans,vector<int>& nums, int idx)
    {
        if(idx==nums.size())
        {
            ans.push_back(nums);
            return;
        }
        set<int> seen;
        for(int i=idx;i<nums.size();i++)
        {
            if(seen.find(nums[i])!=seen.end())
            {
                continue;
                
            }
            seen.insert(nums[i]);
            swap(nums[i], nums[idx]);
            helper(ans,nums, idx+1);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        helper(ans, nums, 0);
        return ans;
        
    }
};
