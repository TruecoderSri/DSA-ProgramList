#include <iostream>
#include <vector>
using namespace std;
// to print the path of the knight on a chessBoard starting from an initial point
// Time Complexity:O(8*(N^2)),Space Complexity:O(1)
void display(vector<vector<int>> &chessBoard)
{
    for (int i = 0; i < chessBoard.size(); i++)
    {
        for (int j = 0; j < chessBoard.size(); j++)
        {
            cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void knightsTour(vector<vector<int>> &chessBoard, int n, int r, int c, int upcoming_moves)
{

    // Invalid Condns.
    if (r < 0 || c < 0 || r >= n || c >= n || chessBoard[r][c] != 0)
    {
        return;
    }
    if (upcoming_moves == n * n)
    {
        chessBoard[r][c] = upcoming_moves;
        display(chessBoard);
        chessBoard[r][c] = 0;
        return;
    }

    chessBoard[r][c] = upcoming_moves;
    // then traversing in all 8 directions
    knightsTour(chessBoard, n, r - 2, c + 1, upcoming_moves + 1);
    knightsTour(chessBoard, n, r - 1, c + 2, upcoming_moves + 1);
    knightsTour(chessBoard, n, r + 1, c + 2, upcoming_moves + 1);
    knightsTour(chessBoard, n, r + 2, c + 1, upcoming_moves + 1);
    knightsTour(chessBoard, n, r + 2, c - 1, upcoming_moves + 1);
    knightsTour(chessBoard, n, r + 1, c - 2, upcoming_moves + 1);
    knightsTour(chessBoard, n, r - 1, c - 2, upcoming_moves + 1);
    knightsTour(chessBoard, n, r - 2, c - 1, upcoming_moves + 1);
    chessBoard[r][c] = 0; // BackTrack
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> chess(n, vector<int>(n, 0));
    knightsTour(chess, n, r, c, 1);
    return 0;
}