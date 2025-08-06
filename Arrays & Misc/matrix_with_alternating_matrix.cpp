#include <iostream>
#include <string>
using namespace std;
void alt(int m, int n)
{
    int k = 0, l = 0;
    int i;
    char a[m][n];
    char x = 'X';
    while (k < m && l < n)
    {
        for (i = 0; i < n; i++)
            char[k][i] = x;
        k++;
        for (i = n - 1; i < m; i++)
            char[i][n - 1] = x;
        n--;
        if (k < m)
        {
            for (i = n - 1; i >= l; i--)
                char[m - 1][i] = x;
            m--;
        }
        if (l < n)
        {
            for (i = m - 1; i >= k; i--)
                char[i][l] = x;
            l++;
        }
        x = ((x == 0) ? 'X' : '0');
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                cout << " " << a[i][j];
                cout << "\n";
            }
        }
    }
}
int main()
{

    return 0;
}