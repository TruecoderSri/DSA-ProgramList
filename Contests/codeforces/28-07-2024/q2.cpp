// #include <bits/stdc++.h>
// using namespace std;

// vector<int> solve(int i, int n, int brr[])
// {
//     vector<int> temp;
//     int ele1, ele2;
//     bool flag = 0;
//     for (int i = 0; i < n; i++)
//     {
//         if (i == 0)
//             ele1 = 0, ele2 = 0;
//         else
//         {
//             ele1 = temp[i - 1];
//             ele2 = 0;
//         }
//         for (int j = 0; j < 32; j++)
//         {
//             if ((brr[i] << j) & 1)
//             {
//                 if (i == 0)
//                 {
//                     ele1 |= (1 << j);
//                     ele2 |= (1 << j);
//                 }
//                 else
//                 {
//                     if ((ele1 << j) & 1 == 0)
//                     {
//                         flag = 1;
//                     }
//                     else
//                         ele2 |= (1 << j);
//                 }
//             }
//             else
//             {
//                 if (i == 0)
//                 {
//                     ele1 |= (0 << j);
//                     ele2 |= (1 << j);
//                 }
//                 else
//                 {
//                     ele2 |= (0 << j);
//                 }
//             }
//         }
//         if (i == 0)
//         {
//             temp.push_back(ele1);
//             temp.push_back(ele2);
//         }
//         else
//             temp.push_back(ele2);
//     }
//     return (flag == 0) ? temp : {-1};
// }

// int main()
// {
//     int t;
//     cin >> t;
//     vector<vector<int>> res;
//     while (t--)
//     {
//         int n;
//         cin >> n;
//         int brr[n - 1];

//         for (int i = 0; i < n - 1; i++)
//         {
//             cin >> brr[i];
//         }
//         vector<int> temp = solve(0, n - 1, brr);
//         res.push_back(temp);
//     }

//     for (auto it : res)
//     {

//         for (auto it1 : it)
//         {
//             cout << it1 << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int n, vector<int> &b)
{
    vector<int> a(n);
    a[0] = b[0]; // Initialize the first element of a

    for (int i = 1; i < n; ++i)
    {
        // Set a[i] such that a[i-1] & a[i] = b[i-1]
        a[i] = b[i - 1] | (a[i - 1] & ~b[i - 1]);
    }

    // Verify if the constructed array a is good
    for (int i = 0; i < n - 1; ++i)
    {
        if ((a[i] & a[i + 1]) != b[i])
        {
            return {-1}; // No valid array a exists
        }
    }

    return a; // Return the constructed array a
}

int main()
{
    int t;
    cin >> t;
    vector<vector<int>> res;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> b(n - 1);
        for (int i = 0; i < n - 1; ++i)
        {
            cin >> b[i];
        }
        vector<int> temp = solve(n, b);
        res.push_back(temp);
    }

    for (auto it : res)
    {

        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }
    return 0;
}
