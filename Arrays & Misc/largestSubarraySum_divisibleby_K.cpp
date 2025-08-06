#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    vector<int> v1;
    int i, n, ele, k;
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> ele;
        v1.push_back(ele);
    }
    cout << "Enter k value:";
    cin >> k;
    int ans = 0, sum = 0;
    map<int, int> res;
    res.insert({0, -1});
    for (i = 0; i < v1.size(); i++)
    {
        sum += v1[i];
        int rem = sum % k;
        if (res.find(rem) == res.end())
            res.insert({rem, i});
        else
            ans = max(i - res[rem], ans);
    }
    cout << "length of longest subarray divisible with k:" << ans << endl;
    return 0;
}