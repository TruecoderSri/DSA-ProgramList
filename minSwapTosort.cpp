#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;
// employing graph approach
int minSwapTosort(int arr[], int n)
{
    pair<int, int> p[n]; // pair to store the (val,index) of each element
    for (int i = 0; i < n; i++)
    {
        p[i].first = arr[i];
        p[i].second = i;
    }
    sort(p, p + n); // sorting the pair on the basis of value of
    int count = 0;
    vector<bool> vis(n, false); // initialising every element in the array to be false
    for (int k = 0; k < n; k++)
    {

        // vis[k] = true;
        if (vis[k] || p[k].second == k)
            /*if the given element/node is visited
            or the respective indexes matches we just proceed*/
            continue;

        int cycle_Size = 0; // var. to store the no of tranfers to the indexes of the values are done
        int j = k;
        while (!vis[j])
        {
            vis[j] = 1;
            j = p[j].second; // algo to store to make a cycle
            cycle_Size++;
        }
        if (cycle_Size > 0)
        {
            count += (cycle_Size - 1); // calc the no of swaps needed to be performed
        }
    }
    return count;
}
int main()
{
    int arr[] = {1, 5, 4, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = minSwapTosort(arr, n);
    cout
        << "MiN NO OF SORTS TO SORT THE GIVEN ARRAY IS:" << ans;

    return 0;
}