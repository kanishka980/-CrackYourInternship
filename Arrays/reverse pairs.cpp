class Solution {
public:
    int c = 0;
    int rev(vector<int>& a, vector<int>& b) {
        int cnt = 0;
        int i = 0, j = 0;
        while (i < a.size() && j < b.size()) {
            long long int temp = b[j];
            if (a[i] > 2 * temp) {
                cnt += a.size() - i;
                j++;
            } else {
                i++;
            }
        }
        return cnt;
    }
    void merge(vector<int>& a, vector<int>& b, vector<int>& temp) {
        int i = 0, j = 0, k = 0;
        while (i < a.size() && j < b.size()) {
            if (a[i] <= b[j]) {
                temp[k++] = a[i++];

            } else {
                temp[k++] = b[j++];
            }
        }
        if (i == a.size()) {
            while (j < b.size()) {
                temp[k++] = b[j++];
            }
        } else if (j == b.size()) {
            while (i < a.size()) {
                temp[k++] = a[i++];
            }
        }
    }
    void mergesort(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return;
        }
        int n1 = n / 2;
        int n2 = n - n / 2;
        vector<int> a(n1), b(n2);
        for (int i = 0; i < n1; i++) {
            a[i] = nums[i];
        }
        for (int i = 0; i < n2; i++) {
            b[i] = nums[n1 + i];
        }
        mergesort(a);
        mergesort(b);
        // apply reverse pair function
        c += rev(a, b);
        // merging the sorted array

        merge(a, b, nums);
    }
    int reversePairs(vector<int>& nums) {
        mergesort(nums);
        return c;
    }
};
