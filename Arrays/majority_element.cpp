class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<pair<int, int>> values;
        int n = nums.size();
        int majority = n / 2;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }
        for (auto &x : mp) {
            if (x.second > majority) {
                return x.first;
            }
        }
        return -1;
    }
};
