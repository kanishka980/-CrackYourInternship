class Solution {
public:
    int dp[201][201];
    vector<vector<int>>nums;
    int solve(int i,int j,int m,int n)
    {
        if(i<0 || i>=m || j<0 || j>=n)
        {
            return INT_MAX;
        }
        if(i==m-1 && j==n-1)
        {
            return nums[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        long right=solve(i,j+1,m,n);
        long down=solve( i+1, j,m,n);
        return dp[i][j]=nums[i][j] +min(right,down);

    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        memset(dp,-1,sizeof(dp));
        nums=grid;
        int ans=solve(0,0,m,n);
        return ans;
        
    }
};
