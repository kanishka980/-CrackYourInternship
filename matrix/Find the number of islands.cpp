//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    void dfs(int i, int j, vector<vector<char>>&grid, vector<vector<int>> &visited)
    {
        vector<int>r={-1,-1,-1,0,0,1,1,1};
        vector<int>c ={-1,0,1,-1,1,-1,0,1};
        visited[i][j]=1;
        int n=grid.size();
        int m=grid[0].size();
        for(int k=0;k<8;k++)
        {
            int newr=i+r[k];
            int ncol=j+c[k];
            if(newr>=0 && newr<n && ncol>=0 
            && ncol<m && grid[newr][ncol]=='1' && !visited[newr][ncol])
            dfs(newr, ncol, grid, visited);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        
        int cnt=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    dfs(i,j,grid, visited);
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

