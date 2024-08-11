class Solution {
public:
    vector<int> prevsmaller(vector<int> &heights)
    {
        vector<int> ps(heights.size(),-1);
        stack<int> s;
        for(int i=0;i<heights.size();i++)
        {
            while(!s.empty() && heights[s.top()]>= heights[i])
            {
                s.pop();
            }
            
            if(!s.empty())
            {
                ps[i]=s.top();
            }
            s.push(i);
        }
        return ps;
    }
    vector<int> nextsmaller(vector<int> &heights)
    {
        vector<int> ns(heights.size(),heights.size());
        stack<int> st;
        for(int i=heights.size()-1;i>=0;i--)
        {
            while(!st.empty() && heights[st.top()]> heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                ns[i]=st.top();
                
            }
            
            st.push(i);
        }
        return ns;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxans=0;
        vector<int> ps=prevsmaller(heights);
        vector<int> ns=nextsmaller(heights);
        for(int i=0;i<heights.size();i++)
        {
            int cur=(ns[i]-ps[i]-1)*(heights[i]);
            maxans=max(maxans,cur);

        }
        return maxans;

        
    }
};
