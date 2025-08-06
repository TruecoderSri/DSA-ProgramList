//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    
    // void kSort(int arr[],int n,int k){
        
    //     int size;
    //     int N=n;
    //     size=(n==k)?k:k+1;
        
    //     priority_queue<int,vector<int>,greater<int>> pq(arr,arr+size);
        
    //     int counter=0;
    //     for(int i=k+1;i<N;i++){
    //         arr[counter++]=pq.top();
    //         pq.pop();
    //         pq.push(arr[i]);
    //     }
        
    //     while(!pq.empty()){
    //         arr[counter++]=pq.top();
    //         pq.pop();
    //     }
    // }
    
    // vector <int> nearlySorted(int arr[], int num, int k){
    //     // Your code here
    //      vector<int> ans;
    //     kSort(arr,num,k);
    //     for(int i=0;i<n;i++)
    //     ans.push_back(arr[i]);
    //     return ans;
        
    // }
    
        vector <int> nearlySorted(int arr[], int n, int k){

        vector<int>v;

         priority_queue<int, vector<int>, greater<int> > pq; 

    

    for(int i=0;i<=k;i++)

        pq.push(arr[i]);

        

 int index = 0; 

 for (int i = k + 1; i < n; i++) { 

 arr[index++] = pq.top(); 

 v.push_back(pq.top());

 pq.pop(); 

 pq.push(arr[i]); 

 } 

 

 while (pq.empty() == false) { 

 arr[index++] = pq.top(); 

 v.push_back(pq.top());

 pq.pop(); 

 } 

 return v;

 

    }
};

//{ Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}

// } Driver Code Ends