//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        int a;
        int n=nums.size();
        vector<int>ans;
        for(int i=0; i<n; i++){
            a^=nums[i];
        }
        int x=0,y=0;
        int set_bit=(a & ~(a-1));
       for(int i=0; i<n; i++){
           if(set_bit&nums[i])
           x^=nums[i];
           else 
           y^=nums[i];
       }
       if(x>y)
       swap(x,y);
       ans.push_back(x);
       ans.push_back(y);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends