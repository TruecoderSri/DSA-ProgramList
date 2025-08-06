#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
// to divide the arr into 2 subsets with equal sub-sum and min possible diff bw elements
void tugOfWar(int arr[], int i, int n, vector<int> v1, vector<int> v2, int s1, int s2, bool ans[], int &diff)
{
    if (i == n)
    {

        if (v1.size() < ((n + 1) / 2))
        {
            if (abs(s1 - s2) < diff)

            {
                diff = abs(s1 - s2);
                for (i = 0; i < n; i++)
                {
                    ans[i] = false;
                }
                for (int j = 0; j < v1.size(); j++)
                    ans[v1[j]] = true;
            }
        }
        return;
    }
    // following a recursion tree
    v1.push_back(i);
    tugOfWar(arr, i + 1, n, v1, v2, s1 + arr[i], s2, ans, diff);
    v1.pop_back(); // backtracking

    v2.push_back(i);
    tugOfWar(arr, i + 1, n, v1, v2, s1, s2 + ans[i], ans, diff);
    v2.pop_back(); // backtracking
}
int main()
{
    int arr[] = {23, 45, -34, 12, 0, 98, -99, 4, 189, -1, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> v1, v2;
    bool ans[n];
    int diff = INT_MAX;
    tugOfWar(arr, 0, n, v1, v2, 0, 0, ans, diff);

    cout << "set 1" << endl;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == true)
            cout << arr[i] << " ";
    }

    cout << endl
         << "set 2" << endl;

    for (int i = 0; i < n; i++)
    {
        if (ans[i] == false)
            cout << arr[i] << " ";
    }

    cout << endl;
    cout << "mindiff is " << diff << endl;

    return 0;
}