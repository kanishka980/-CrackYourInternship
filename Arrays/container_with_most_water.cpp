class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int vol = 0;
        while (l < r) {
            int lh = height[l];
            int rh = height[r];
            int h = min(lh, rh);
            vol = max(vol, h * (r - l));
            if (lh < rh) {
                l++;
            } else {
                r--;
            }
        }
        return vol;
    }
};
