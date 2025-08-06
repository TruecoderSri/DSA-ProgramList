//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array 
// of jobs with deadlines and profits 
#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 


// } Driver Code Ends
/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    
     static bool greatest(Job a,Job b){
        return a.profit>b.profit;
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        
       sort(arr,arr+n,greatest);
       
       int maxi=arr[0].dead;
       /*made an array with the size of the the max deadlines among all jobs
       found the max deadline to initialize*/
       for(int i=1;i<n;i++){
           
           if(arr[i].dead>maxi){
               maxi=arr[i].dead;
           }
       }
        int result[maxi+1];
        vector<int> ans(2,0);
        //initialised all the values to '-1'
        for(int i=0;i<=maxi;i++){
            result[i]=-1;
        }
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>0;j--){
                //traversed through the result array if empty space found updated with its Id
                if(result[j]==-1){
                    result[j]=arr[i].id;
                    ans[0]++;
                    ans[1]+=arr[i].profit;
                    break;
                }
            }
        }
        
        return ans;
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}



// } Driver Code Ends