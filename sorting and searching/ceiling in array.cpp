#include<iostream>
#include<vector>
using namespace std;
int ceil(vector<int> a, int x)
{
    int mid;
    int low=0;
    int high=a.size()-1;
    int res=-1;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==x)
        {
            return mid;
        }
        else if(a[mid]<x)
        {
            low=mid+1;;
        }

        else 
        {
            res=mid;
            high=mid-1;
        }
    }
    return res;

}
int main()
{
    vector<int> a={1, 2, 8, 10, 11, 12, 19};
    int x;
    
    cout<<"enter the value of x"<<endl;
    cin>>x;
    int result=ceil(a,x);
    cout<<result<<endl;
    return 0;
}
