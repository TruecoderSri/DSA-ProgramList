#include <bits/stdc++.h>
using namespace std;

void printEgyptian(int nr, int dr)
{
    if (dr == 0 || nr == 0)
    {
        return;
    }
    // the fraction turns out to be an integer
    else if (nr % dr == 0)
    {
        cout << nr / dr;
        return;
    }
    // like 2/6 represented by 1/3
    else if (dr % nr == 0)
    {
        cout << "1/" << dr / nr;
        return;
    }

    else if (nr > dr)
    {
        cout << nr / dr << "+";
        printEgyptian(nr % dr, dr);
        return;
    }
    int n = (dr / nr) + 1; // find the ceil of the fraction
    cout << "1/" << n << "+";
    // recur of the remaining fraction
    printEgyptian(nr * n - dr, dr * n);
}

int main()
{
    int nr = 6, dr = 14;
    cout << nr << "/" << dr << "-> ";
    printEgyptian(nr, dr);
    return 0;
}