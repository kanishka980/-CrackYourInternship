class Solution {
public:
    int rectanglearea(vector<int> &heights)
    {
        stack<int> st;
        int maxa=0;
        int n=heights.size();
        for(int i=0;i<=n;i++)
        {
            while(!st.empty() &&(i==n || heights[st.top()]>=heights[i]) )
            {
                int h=heights[st.top()];
                st.pop();
                int w;
                if(st.empty())
                {
                    w=i;
                }
                else
                {
                    w=i-st.top()-1;
                }
                maxa=max(maxa, h*w);
            }
            st.push(i);
        }
        return maxa;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
       
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> heights(m,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')
                {
                    heights[j]+=1;
                }
                else
                {
                    heights[j]=0;
                }
            }
            int area=rectanglearea(heights);
            ans=max(ans,area);

        }
        return ans;
        
    }
};
