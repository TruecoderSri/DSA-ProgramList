#include <iostream>
#include <vector>
using namespace std;
bool givensum(vector<int> &v, int n, int sum)
{
    int i;
    for (i = 0; i < n; i++)

        if (v[i] > v[i + 1])
        {
            break;
        }
    int l = (i + 1) % n;
    int r = i;
    while (l != r)
    {
        if (v[l] + v[r] == sum)
            return true;
        else if (v[l] + v[r] < sum)
            l = (l + 1) % n;
        else
            r = (r + n - 1) % n;
    }
}
int main()
{
    vector<int> v;
    int n, ele, sum;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        v.push_back(ele);
    }
    cout << "Enter the sum to search for";
    cin >> sum;
    if (givensum(v, n, sum) == 1)
        cout << "True\n";
    else
        cout << "Sorry the sum could not be found\n";
    // cout << "The given sum is:" << givensum(v, n, sum);
    return 0;
}