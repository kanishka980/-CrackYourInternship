class Solution {
public:
    void solve(int openp, int closep, int n,string s,vector<string>&res)
    {
        if(openp==closep && openp+closep==2*n)
        {
            res.push_back(s);
            return;
        }
        if(openp<n)
        {
            solve(openp+1,closep,n,s+"(",res);
        }
        if(closep<openp)
        {
            solve(openp, closep+1,n,s+")",res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        
        solve(0,0,n,"",res);
        return res;
        
    }

};
