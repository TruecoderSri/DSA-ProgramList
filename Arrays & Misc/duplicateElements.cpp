#include <iostream>
#include <vector>
using namespace std;
// TIME COMPLEXITY (N)
int main()
{
    vector<int> ans;
    int n;
    cin >> n;
    int arr[n], visited[n] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        visited[arr[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        if (visited[i] > 1)
        {
            ans.push_back(i);
        }
    }

    for (int i = 0; i < ans.size(); i++)
    {
        cout << "Duplicate elements is/are:" << ans.at(i) << "\t";
    }
    return 0;
}