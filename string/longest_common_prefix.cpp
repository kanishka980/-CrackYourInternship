class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int arr_length=size(strs);
        
        sort(strs.begin(),strs.end());
        
        string first=strs[0];
        string last=strs[arr_length-1];
        string ans="";
        for(int i=0;i<first.length();i++)
        {
            if(first[i]==last[i])
            {
                ans+=first[i];
                
            }
            
            else break;
        }
        return ans;
        
    }
};
