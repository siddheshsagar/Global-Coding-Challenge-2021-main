#include <bits/stdc++.h>
using namespace std;

vector<int> sendrem(int k,int b, int c,vector< vector<int> > &a,vector<int>&vans)
{
   int n=c;
   int diff=0;
   int diff_sum=0;
   int count=0;
   int idx;
   vector<int>v;
   for(int i=0;i<n;i++)
   {
       if(vans[i]<=a[k][i])
           v.push_back(vans[i]);
       
       else
           v.push_back(-1);
   }

    int i=0;
    int max=0;
    int max_count=0;
    for(int i=0;i<n;i++)
    {
        diff=0;
        count=0;
        diff_sum=0;
        if(v[i]==-1)
        {
            for(int j=i;j<n+1;j++)
            {
                if(v[j]==-1)
                {
                    diff=0;
                    diff=vans[j]-a[k][j];
                    count++;
                    diff_sum=diff_sum+diff;
                    i=j;
                }
                else
                {
                    if(max<diff_sum)
                    {
                        max=diff_sum;
                        idx=j-count;
                        max_count=count;
                    }
                    i=j;
                    break;
                }
            }
        }
    }
    int l=0;
    
    for(int i=0;i<n;i++)
    {
        if(v[i]==-1)
        {
            if(i==idx)
            {
                l=i;
                for(int j=0;j<max_count;j++)
                {
                    v[l]=a[k][l];
                    l++;
                }
            }
            else
                v[i]=vans[i];
        }
    }
    return v;
}
vector<int> sendfirst(int i,int b, int c,vector< vector<int> > &a,vector<int>&vans) 
{
   int n=c;
   vector<int>v;
   int sum1=0;
   int sum2=0;
   int totsum1=0;
   int totsum2=0;
    for(int j=0;j<n;j++)
    {
        sum1=sum1+a[0][j];
        sum2=sum2+a[1][j];
    }
    
    if(sum1<sum2)
        v.push_back(sum1);
    else
        v.push_back(sum2);
    for(int j=1;j<n;j++)
    {
        sum1=sum1-a[0][n-j]+a[1][n-j];
        sum2=sum2-a[1][n-j]+a[0][n-j];
    
        if(sum1<sum2)
        v.push_back(sum1);
        else
        v.push_back(sum2);
    }
    int min=v[0];
    int minidx=0;
    for(int i=0;i<n;i++)
    {
        if(min>v[i])
        {
            min=v[i];
            minidx=i;
        }
    }
  
    vector<int>v1;
    vector<int>v2;
    for(int j=0;j<n+1;j++)
    {
        if(j>=n-minidx)
        {
            v1.push_back(a[1][j]);
            v2.push_back(a[0][j]);
            totsum1=totsum1+a[1][j];
            totsum2=totsum2+a[0][j];
        }
        else
        {
            v1.push_back(a[0][j]);
            v2.push_back(a[1][j]);
            totsum1=totsum1+a[0][j];
            totsum2=totsum2+a[1][j];
        }
       
    }
    if(totsum1<totsum2)
    return v1;
    else
    return v2;
}

int main()
{
    int b,c;
    cin >> c>>b;
    int answer=0;
    vector<int>vans;
    vector<int>vrem;
    vector<vector<int>> time(b,vector<int>(c));
    
    for(int i = 0; i < b; i++)
        for(int j = 0;j < c;j++)
            cin>>time[i][j];
        
    if(b==1)
    {
        for(int i=0;i<c;i++)
            answer+=time[0][i];
    }
    else
    {
        for(int i=0;i<b;i++)
        {
            if(i==0)
            {
                vans=sendfirst(i,b,c,time,vans);
                i++;
            }
        }
    }
        
    for(int i = 0; i < b; i=i+1)
    {
        if(i==0)
        {
            vans=sendfirst(i,b,c,time,vans); 
            i=i+1;
        }
        else
        {
            vans=sendrem(i,b,c,time,vans);
            cout<<endl;
        }
    }
    for(int i=0;i<c;i++)
        answer=answer+vans[i];
     
    cout<< answer << endl;
    return 0;
}