class Solution {
public:
    bool issafe(vector<vector<int>>& grid, int i, int j) {
        int r = grid.size();
        int c = grid[0].size();
        if (i >= 0 && i < r && j >= 0 && j < c) {
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int mins = 0;
        vector<pair<int, int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        while (!q.empty()) {
            bool rotted = false;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> current = q.front();
                q.pop();
                for (auto x : dir) {
                    int newi = current.first + x.first;
                    int newj = current.second + x.second;
                    if (issafe(grid, newi, newj) && grid[newi][newj] == 1) {
                        grid[newi][newj] = 2;
                        q.push({newi, newj});
                        fresh--;
                        rotted = true;
                    }
                }
            }
            if (rotted) {
                mins++;
            }
        }
        if (fresh == 0) {
            return mins;
        }
        return -1;
    }
};
