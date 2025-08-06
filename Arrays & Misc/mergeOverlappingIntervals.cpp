#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<vector<int>> v1;
    int i, ele, t, j;
    cout << "test cases\n";
    cin >> t;
    for (i = 0; i < t; i++)
    {
        vector<int> v2;
        for (j = 0; j < 2; j++)
        {
            cin >> ele;
            v2.push_back(ele);
        }
        v1.push_back(v2);
    }
    sort(v1.begin(), v1.end());
    vector<vector<int>> n;
    vector<int> curr = v1[0];
    for (i = 1; i < v1.size(); i++)
    {
        if (curr[1] <= v1[i][0])
        {
            n.push_back(curr);
            curr = v1[i];
        }
        else
        {
            curr[1] = max(curr[1], v1[i][1]);
        }
    }
    n.push_back(curr);
    cout << "Overlapped Intervals:";
    for (i = 0; i < n.size(); i++)
    {
        for (j = 0; j < n[i].size(); j++)
        {
            cout << n[i][j] << "\t";
        }
    }
    return 0;
}