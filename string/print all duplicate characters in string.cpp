#include<iostream>
using namespace std;
#include<string>
#include<map>
#include <bits/stdc++.h>
void count(string s)
{
    unordered_map<char,int> mp;
    for(int i=0;i<s.length();i++)
    {
        mp[s[i]]++;
    }

    //printing the duplicates
    for(auto it: mp)
    {
        if(it.second>1)
        {
            cout << it.first <<" : "<< it.second<<endl;
        }
    }
}
int main()
{
    string s="Helloo";
    count(s);
    return 0;

}
