

class Solution
{
public:
    void solve(int col, vector<vector<string>> &ans, vector<string> &board, vector<int> &leftrow, vector<int> &lowerDiagonal, vector<int> &upperDiagonal, int n)
    {
        if (col == n)
        {
            ans.push_back(board);
            return;
        }
        /* We check the upperD,lowerD and the left row because we're filling the queens from L->R so these are the places
        where the Queen maybe present already.
        We hash using 3 vectors to get rid of n complexity coming on all the 3 traversals adding upto 3n. */
        for (int row = 0; row < n; row++)
        {
            if (leftrow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDiagonal[n - 1 + col - row] == 0)
            {
                board[row][col] = 'Q';
                leftrow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;
                solve(col + 1, ans, board, leftrow, lowerDiagonal, upperDiagonal, n);
                board[row][col] = '.'; // backtrack to bring in next possibility of placing the Queens
                leftrow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        // code here
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        vector<int> leftrow(n, 0);
        vector<int> upperDiagonal(2 * n - 1, 0);
        vector<int> lowerDiagonal(2 * n - 1, 0);
        solve(0, ans, board, leftrow, lowerDiagonal, upperDiagonal, n);
        return ans;
    }
};