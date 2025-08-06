//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int maxi=INT_MIN;
	    int curr_max=0;
	    for(int i=0;S[i]!='\0';i++){
	        int x=(S[i]=='0')?1:-1;
	        curr_max+=x;
	        if(curr_max>maxi)
	        maxi=curr_max;
	        if(curr_max<0)
	        curr_max=0;
	    }
	    return maxi;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}

// } Driver Code Ends