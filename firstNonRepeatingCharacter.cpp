//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		  //  to keep count of which char are there
		  vector<int>vis(26,0);
		  //to keep track of which char is present first
		    vector<int> v;
		    string ans="";
		    for(int i=0;i<A.size();i++){
		        
		        if(!vis[A[i]-'a'])
		        v.push_back(A[i]);
		        
		     vis[A[i]-'a']++;
		     int flag=0;
		     for(int j=0;j<v.size();j++){
		         if(vis[v[j]-'a']==1){
		             ans.push_back(v[j]);
		             flag=1;
		             break;
		         }
		     }
		      if(flag==0)
		      ans.push_back('#');
		   }
		     return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends