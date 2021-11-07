#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string solution(string n)   // first find the first two maximum continuous sub-sequense of zeros and then check the conditions
{
    string str1("A");
    string str2("B");
    if(n.length()==0)
        return str2;
    vector<int>v;
    int CurrCnt=0;
    for(int i=0;i<n.length();i++)
    {
        if(n[i]=='0')
            CurrCnt++;
        else 
        {
            if(CurrCnt!=0)
            {
                v.push_back(CurrCnt);
                CurrCnt=0;
            }
        }
    }
    if(CurrCnt!=0)
        v.push_back(CurrCnt);
    if(v.size()==0)
        return str2;
    int maxi=INT_MIN, j;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]>maxi)
        {
            maxi=v[i];
            j=i;
        }
    }
    v[j]=-1;
    int maxi2=INT_MIN;
    for(int i=0;i<v.size();i++)
        if(v[i]>maxi2)
            maxi2=v[i];
    
    if((maxi2==maxi and maxi2%2!=0) or maxi%2==0)
        return str2;
    return str1;
}

/*  Do not edit below code */
int main() {
	string  n;
	cin >> n;	
    string answer=solution(n);
	cout << answer << endl;	
}
