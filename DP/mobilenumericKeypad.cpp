//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{


	public:
	

long long dp[10][30];
long long solve(int board[4][3], int i, int j, int N) {
    
    // adding constraints
    if(i < 0 or j < 0 or i >= 4 or j >= 3 or board[i][j] == -1) return 0;
    
    if(N == 1) {
        if(board[i][j] != -1) {
            return 1;
        }else {
            return 0;
        }
    }
    
    if(dp[board[i][j]][N] != -1) return dp[board[i][j]][N];
    
    long long  up = solve(board, i+1, j, N - 1);
    long long  left = solve(board, i, j - 1, N - 1);
    long long  right = solve(board, i, j+1, N - 1);
    long long  down = solve(board, i-1, j, N - 1);
    long long  self = solve(board, i, j, N - 1);
    
    return dp[board[i][j]][N] = up+left+right+down+self;
}
long long getCount(int N)
{
 // Your code goes here
 int board[4][3] = { 
                1, 2, 3,
                4, 5, 6,
                7, 8, 9,
                -1, 0, -1
                };
                
   
 memset(dp, -1, sizeof(dp));

 long long cnt = 0;
 for(int i = 0; i < 4; i++) {
     for(int j = 0; j < 3; j++) {
         if(board[i][j] != -1) {
             cnt += solve(board, i, j, N);
         }
     }
 }
 return cnt;
}


};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends