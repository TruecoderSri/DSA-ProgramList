//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends


class Solution
{
    public:
    void sort012(int a[], int n)
    {
    //     // code here
    //     // counting approach
        
    //     int count[3]={0};
    //   for(int i=0;i<n;i++){
    
    //   count[a[i]]++;
               
    //   }
    //   int z=count[0];
    //   int o=count[1];
    //   int t=count[2];
    // for(int i=0;i<z;i++){
    //         a[i]=0;
    //     }
    //     for(int i=z;i<o+z;i++){
    //         a[i]=1;
    //     }
    //     for(int i=o+z;i<(z+t+o);i++){
    //         a[i]=2;
    //     }
        
    // }

// Dutch National Flag Algorithm

// TC:O(N)
// SC:O(1)
    
    long long low=0;
    long long mid=0;
    long long high=n-1;
    
    while(mid<=high){
        if(a[mid]==0){
           swap(a[mid++],a[low++]);
            
        }
        else if(a[mid]==1){
            mid++;
            
        }
        else{
            swap(a[mid],a[high]);
            high--;
        }
       
    }
    
    
    
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends