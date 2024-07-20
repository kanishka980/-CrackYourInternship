class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        if (n == 0) {
            return 0;
        }
        int count = 0;
        int curr_sum = 0;
        int i = 0;
        while (i < n) {
            curr_sum += nums[i];
            if (curr_sum == k) {
                count += 1;
            } else if (mp.find(curr_sum - k) != mp.end()) {
                count += mp[curr_sum - k];
            }
            mp[curr_sum] += 1;
            i += 1;
        }
        return count;
    }
};
