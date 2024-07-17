class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int sum = 0;
        int n = cardPoints.size();
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[i];
        }
        int res = sum;
        for (int i = 0; i < k; ++i) {
            sum += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            res = max(sum, res);
        }
        return res;
    }
};
