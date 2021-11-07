#include <iostream>
#include <string>
#include <stdio.h>
#include <ctype.h>
#include <vector>
#include <queue>
#include<algorithm>
#include <sstream>
#include <typeinfo>
#include <bits/stdc++.h>
using namespace std;
 
int securitiesBuying(int z,int arr[],int n)
{
    int ans=0;
    int PTN=0;
    vector< pair <int,int> > v;
    for (int i=0; i<n; i++) 
        v.push_back({arr[i],i+1});
    sort(v.begin(), v.end());
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<v[i].second;j++)
        {
            if(PTN+v[i].first>z)
                return ans;
            PTN+=v[i].first;
            ans++;
        }
    }
    return ans;
}
 
int main(){
 
int z;
cin>>z;
vector<int> input_data;
string buffer;
int data;
getline(cin, buffer);
getline(cin, buffer);
istringstream iss(buffer);
 
 
while (iss >> data)
    input_data.push_back(data);
 
int n= input_data.size();
 
 
 int security_value[n];
    for (int i = 0; i < n; i++) {
        security_value[i] = input_data[i];
    }
 
 
 
int no_of_stocks_purchased = securitiesBuying(z,security_value,n);
cout << no_of_stocks_purchased;
 
 
 
}
 
 
