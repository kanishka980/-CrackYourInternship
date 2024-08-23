//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with samecolour.
    
    bool isSafe(int node, int color[], bool graph[101][101], int n, int col) {
        for (int k = 0; k < n; k++) {
            if (graph[node][k] && color[k] == col) {
                return false;
            }
        }
        return true;
    }

    // Utility function to solve the graph coloring problem using backtracking
    bool graphColoringUtil(int node, int m, int n, int color[], bool graph[101][101]) {
        if (node == n) {
            return true;
        }

        // Trying different colors for the current vertex
        for (int col = 1; col <= m; col++) {
            if (isSafe(node, color, graph, n, col)) {
                color[node] = col;

                // Recursively call the function to color the next vertex
                if (graphColoringUtil(node + 1, m, n, color, graph)) {
                    return true;
                }

                // If coloring this vertex with col doesn't lead to a solution
                // then backtrack by removing the color
                color[node] = 0;
            }
        }

        // If no color can be assigned to this vertex, return false
        return false;
    }

    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        int color[101] = {0};

        // Start coloring vertices from vertex 0
        return graphColoringUtil(0, m, n, color, graph);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends
