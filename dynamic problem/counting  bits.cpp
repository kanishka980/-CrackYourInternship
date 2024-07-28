class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> c(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            c[i] = bitscount(i);
        }
        return c;
    }
    int bitscount(int x) {
        if (x <= 0) {
            return 0;
        } else {
            return (x & 1) + bitscount(x >> 1);
        }
    }
};
