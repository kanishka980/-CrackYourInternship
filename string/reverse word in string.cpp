class Solution {
public:
    string reverseWords(string s) {
        string temp="";
        stack<string> st;
        int n=s.length();
        string res="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                if(!temp.empty())
                {
                    st.push(temp);
                    temp="";
                }
                
            }
            else
            {
                temp+=s[i];
            }
        }
        if(!temp.empty())
        {
            st.push(temp);

        }
        while(st.size()!=1)
        {
            res+=st.top()+" ";
            st.pop();            
        }
        res+=st.top();
        return res;
        
    }
};
