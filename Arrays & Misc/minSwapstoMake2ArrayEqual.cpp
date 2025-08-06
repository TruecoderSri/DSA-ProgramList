#include<bits/stdc++.h>

using namespace std;

int minSwaps(int b[],int n){
    
    vector<pair<int,int>>v(n);
    for(int i=0;i<n;i++){
        v[i]={b[i],i};
    }
    sort(v.begin(),v.end());
    
    int swaps=0;
    for(int i=0;i<n;i++){
        if(i==v[i].second)continue;
        else{
            swap(v[i],v[v[i].second]);
            swaps++;
            i--;
        }
    }
    return swaps;
    
}


int minSwapToMakeArraySame(int a[],int b[],int n){
    
   map<int,int> mp;
    for(int i=0;i<n;i++){
        mp[b[i]]=i;
        
    }
    for(int i=0;i<n;i++){
        b[i]=mp[a[i]];
    }
    return minSwaps(b,n);
}

int main()
{
    int a[] = {3, 4, 6, 8};
    int b[] = {4, 6, 8, 3};
 
    int n = sizeof(a) / sizeof(int);
    cout << minSwapToMakeArraySame(a, b, n);
    return 0;
}