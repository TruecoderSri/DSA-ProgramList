//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
               unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]%k]++;
        }
        // since we cannot pair 0 with anything ,0=>the number is already divisible so it should be in a multiple of 2 to pair
        if(m[0]%2==1)
        return false;
        for(int i=1;i<k;i++)
        {
            // a number to be divisible the complement should exit  ie k-a[i]
            if(m[i]!=m[k-i])
            return false;
        }
        return true;
    }
    
    
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends