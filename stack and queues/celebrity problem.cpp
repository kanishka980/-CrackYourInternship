class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    bool knows(vector<vector<int> >& mat, int i, int j)
    {
        return mat[i][j];
    }
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        stack<int> st;
        for(int i=0;i<n;i++)
        {
            st.push(i);
        }
        while(st.size()>1)
        {
            int a=st.top();
            st.pop();
            int b=st.top();
            st.pop();
            
            if(knows(mat,a,b))
            {
                st.push(b);
            }
            else
            {
                st.push(a);
            }
            
        }
        int c=st.top();
        st.pop();
        for(int i=0;i<n;i++)
        {
            if((i != c) && (knows(mat,c, i ) || !knows(mat,i, c)))
                return -1;
                
        }
        return c;
    }
};
