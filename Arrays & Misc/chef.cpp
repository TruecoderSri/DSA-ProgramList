#include <iostream>
using namespace std;

int main()
{
    // your code goes here
    int n, t, arr[1000];
    int i, j, sum = 0, c = 0;
    cin >> t;
    while (t)
    {
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (j = 0; j < n; j++)
        {
            sum += arr[j];
        }
        if (sum == 0)
        {
            cout << "0" << endl;
        }
        else if (n % 2 != 0)
        {
            cout << "-1" << endl;
        }
        else
        {
            c = sum / 2;
            cout << c << endl;
        }
        sum = 0;
        c = 0;
        t--;
    }
    return 0;
}
