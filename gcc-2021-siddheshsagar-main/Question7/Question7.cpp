#include <bits/stdc++.h> 
#include <cstdlib> 
using namespace std; 




 
typedef long long ll;  

int hm[1000001]; 
int rr[1000001]; 

void make_set(int v) 
{ 
    rr[v]=0; 
    hm[v] = v; 
     
} 

int find_set(int v)  
{ 
    if (v == hm[v]) 
        return v; 
    return hm[v]=find_set(hm[v]); 
} 

void union_sets(int a,int b)  
{ 
    a = find_set(a); 
    b = find_set(b); 
    if (a != b) 
	{ 
        if (rr[a] > rr[b]) 
		{ 
           hm[b] = a; 
        } 
        else if(rr[a]<rr[b]) 
        { 
            hm[a]=b; 
        } 
        else
		{ 
            hm[a]=b; 
            rr[a]++; 
        } 
    } 
} 
 
 
int power(long long int xx,int count,int MOD ) 
{ 


	if(xx==0 || xx==1)
	  	return xx%MOD; 
	
	if(count==0) 
	 	return 1; 
	
	if(MOD==1) 
	 	return 0; 
  	
	long long int attri=1; 
	while(count)
	{ 
        if(count%2) 
        	attri=(attri*xx)%MOD; 
        xx=(xx*xx)%MOD; 
        count/=2; 
    } 
 	return attri; 
} 
 
void tim() 
{ 
           
    int ans=0; 
    int MOD=1000000007; 

    int n; 
    cin>>n; 
    int arr[n]; 
    int maxi=INT_MIN; 
    bool yesone=false; 
    
    for(int i=0;i<n;i++) 
    { 
        cin>>arr[i]; 
        if(arr[i]==1) 
            yesone=true; 
        maxi=max(maxi,arr[i]); 
    } 
    
    sort(arr,arr+n); 
    
    for(int i=0;i<maxi+1;i++)  
        rr[i]=-1;  
    
    for(int i=0;i<n;i++) 
    { 
        int val=arr[i]; 
        set<int> s; 
        int start=0; 
        
        while (val % 2 == 0) 
        { 
            if(start==0) 
            { 
                s.insert(2); 
                start=1; 
            } 
            val = val/2; 
        } 

        for (int i = 3; i <= sqrt(val); i = i + 2) 
        { 
            while (val % i == 0) 
            { 
                s.insert(i); 
                val = val/i; 
            } 
        } 
        if (val > 2)
			s.insert(val); 
            
		set<int>:: iterator it;                                
        for(it=s.begin();it!=s.end();it++) 
        { 
             
                if(hm[*it]!=0){continue;} 
                make_set(*it); 
                                
        } 
        set<int> :: iterator it1; 
        it1=s.begin(); 
 
        for(it=s.begin();it!=s.end();it++) 
        	union_sets(*it,*it1); 
                            
        s.clear(); 
    } 
                         
    int count=0; 
    for(int i=2;i<=maxi;i++) 
        if(hm[i]==i  ) 
        	count++; 
             
    if(yesone==true)
		count++;
    int xx=2; 
    ans=power(xx,count,MOD); 
    ans=ans-2; 
    if(ans<2) 
    { 
        cout<<"NO"<<endl; 
        cout<<0<<endl; 
    } 
    else
	{ 
        cout<<"YES"<<endl; 
        cout<<ans<<endl; 
    } 
} 
             
int main() 
{ 
    ios_base::sync_with_stdio(false);  
    cin.tie(NULL); 
    int t=1; 
    
    while(t--)               
        tim();    
}