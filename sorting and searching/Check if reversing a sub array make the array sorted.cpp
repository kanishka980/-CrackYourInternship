#include<iostream>
using namespace std;
#include<vector>
bool check(vector<int> a,int n)
{
    int i;
    for(i=1;i<n ;i++)
    {
        if(a[i]>a[i-1])
        {
            i++;
        }
        else{
            break;
        }
    }
    
    for(int j=i;j<n;j++)
    {
        if(a[j-1]>a[j])
        {
            return true;
        }
    }
    return false;


}
int main()
{
    vector<int> a= {1, 3, 4, 10, 9, 8};
    cout << check(a,6)<<endl;
    return 0;
}
