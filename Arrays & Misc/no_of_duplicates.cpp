#include <iostream>
#include <map>
using namespace std;
#define r 5
#define c 5
void duplicates(int mat[r][c])
{

    map<int, int> m1;
    for (int i = 0; i < r; i++)
    {
        m1.insert(mat[0][i], 1);
        {
            for (int i = 1; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (m1.find(mat[i][j]) && (mat[i][j] == i))
                    {
                        m1.insert(mat[i][j], ((mat[i][j]) + 1));
                    }
                }
                if (i == r - 1 && m1.find(mat[i][j]) && mat[i][j] == r)
                {
                    cout << mat[i][j] << " " l;
                }
            }
        }
    }
}
int main()
{
    int mat[r][c] = {
        {1, 2, 3, 4, 5},
        {2, 4, 5, 8, 10},
        {3, 5, 7, 9, 11},
        {1, 3, 5, 7, 9},
    };
    duplicates(mat);
    return 0;
}