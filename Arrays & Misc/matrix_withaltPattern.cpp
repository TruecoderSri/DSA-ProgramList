#include <iostream>
using namespace std;
void alt(int m, int n)
{
    int k = 0, l = 0;
    int i;
    int r = m, c = n;
    char a[m][n];
    char x = 'X';
    while (k < m && l < n) // initil condn.
    {
        for (i = l; i < n; i++) // to print the first row from remaining rows
            a[k][i] = x;
        k++;
        for (i = k; i < m; i++) // to print the last column from remaining columns
            a[i][n - 1] = x;
        n--;

        if (k < m)
        {
            for (i = n - 1; i >= l; i--) // print the last row from the rem rows
                a[m - 1][i] = x;
            m--;
        }

        if (l < n)
        {
            for (i = m - 1; i >= k; i--) // print the first column from the rem columns
                a[i][l] = x;
            l++;
        }

        x = (x == '0') ? 'X' : '0'; // swap the char after each iteration
    }
    for (int i = 0; i < r; i++) // print the pattern
    {
        for (int j = 0; j < c; j++)
        {
            cout << " " << a[i][j];
        }
        cout << "\n";
    }
}
int main()
{
    alt(3, 3);
    alt(6, 6);
    return 0;
}