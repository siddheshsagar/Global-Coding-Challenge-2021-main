#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

int gcd(int a,int b){
    if(b==0)
       return a;
    return gcd(b,a%b);
}

int* input(int n)
{
    int *arr = new int[n];
    for(int i=0;i<n;i++)
        cin >> arr[i];
    return arr;
}

int rec3(const int *arr,const int *arr_b,int i,int j,int d)
{
    int hello = min(i+d,j);
    int ans = arr_b[hello] - arr_b[i];
    if(hello < j){
        ans += arr[j] - arr[hello];
    }
    return ans;
}

int rec2(int start,int n,int k,int d,int *prefix,int *prefixMul){
    if(start>=n-1){
        return 0;
    }
    if(k==1){
        int ans = -1;
        int r;
        for(int i=start;i<n;i++){
            int z = 0;
            if(i==start){
                z = 0 + rec3(prefix,prefixMul,i,n-1,d);
            }else{
               z  =  prefix[i-1] + rec3(prefix,prefixMul,i,n-1,d);
            }
            ans = max(ans,z);
        }
        return ans;
    }
    int ans = -1;
    for(int i=start;i<n;i++) {
        int a = rec3(prefix,prefixMul,start,i,d);
        int b;
        if(i==0){
            b = 0;
        }else{
            b = prefix[i-1] - prefix[start];
        }
        int temp = a + b + rec2(i+1,n,k-1,d,prefix,prefixMul);
        ans = max(ans, temp);
    }
    return ans;
}

int rec1(vector<int>&arr,int n,int k,int d,int m){
    int possMem[n];
    int poss[n];

    poss[0] = arr[0];
    possMem[0] = arr[0];
    possMem[0] = possMem[0] * m;

    for(int i=1;i<n;i++){
        poss[i] = poss[i-1] + arr[i];
    }
    for(int i=1;i<n;i++){
        possMem[i] = ((int)arr[i]*m) + possMem[i-1];
    }

    return rec2(0,n,k,d,poss,possMem);
}


signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int>v(4);
    for(int i=0;i<4;i++){
        cin >> v[i];
    }
    int n = v[0], y = v[1], z = v[2], m = v[3];
    vector<int>v1;
    for(int i=0;i<n;i++)
	{
        int curr;
        cin >> curr;
        v1.push_back(curr);
    }
    int answer = rec1(v1,n,y,z,m);
    cout << answer << endl;
    return 0;
}