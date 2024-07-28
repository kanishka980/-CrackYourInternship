//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    int t[10001];
    public:
    int solve(int n,int x, int y, int z)
    {
        if(n==0)
        {
            return 0;
        }
        if(t[n]!=-1) return t[n];
        int o1=INT_MIN,o2=INT_MIN,o3=INT_MIN;
        if(n>=x)
        {
            o1=solve(n-x,x,y,z);
            
           
            
        }
        if(n>=y)
        {
            o2=solve(n-y,x,y,z);
            
        }
        if(n>=z)
        {
             o3=solve(n-z,x,y,z);
            
        }
        return t[n]=1+ max(o1,max(o2,o3));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(t,-1,sizeof(t));
        int ans=solve(n,x,y,z);
        if(ans<0) return 0;
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
