class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowbegin = 0;
        int colbegin = 0;
        int rowend = matrix.size() - 1;
        int colend = matrix[0].size() - 1;
        vector<int> ans;
        while (rowbegin <= rowend && colbegin <= colend) {
            // traversing right
            for (int j = colbegin; j <= colend; j++) {
                ans.push_back(matrix[rowbegin][j]);
            }
            rowbegin++;
            // traversing down
            for (int i = rowbegin; i <= rowend; i++) {
                ans.push_back(matrix[i][colend]);
            }
            colend--;
            // traversing left
            if (rowbegin <= rowend) {
                for (int j = colend; j >= colbegin; j--) {
                    ans.push_back(matrix[rowend][j]);
                }
                rowend--;
            }
            // traversing up
            if (colbegin <= colend) {
                for (int i = rowend; i >= rowbegin; i--) {
                    ans.push_back(matrix[i][colbegin]);
                }
                colbegin++;
            }
        }
        return ans;
    }
};
