
#include <bits/stdc++.h>
using namespace std;

int totalPairs(int n, vector<int>& a) 
{
    int max=0,count=0;
    int k;
    for(int i=0;i<n-2;i++)
    {
        max=a[i+1];
        for(int j=i+2;j<n;j++)
        {
            k=a[i]>=a[j]?a[j]:a[i];
            if((k>max) and (a[j]>a[j-1]))
            {
                max=a[j];
                count++;
            }
            if(a[i]<max) break;
        }
    }   
    return count+(n-1);
}

int main(){
   int n;
   cin >> n;
   vector<int> values(n);
   for (int i = 0; i < n; ++i) {
        cin >> values[i];
   }
	int answer = totalPairs(n, values);
    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line
        
    return 0;
}
