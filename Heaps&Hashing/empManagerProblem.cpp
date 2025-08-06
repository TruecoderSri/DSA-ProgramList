#include <bits/stdc++.h>
using namespace std;
// TC:o(nlogn)
// SC:o(N)

// here f is the ceo and rest are employees
/*     F
     3/ \2
     C   E1
   1/ \1   \1
   A   B    D  */
int count(unordered_map<string, unordered_set<string>> &hashMap, string man, map<string, int> &ans)
{
    if (hashMap.find(man) == hashMap.end())
    {
        ans[man] = 0;
        return 1;
    }
    int size = 0;
    for (auto emp : hashMap[man])
    {
        int cs = count(hashMap, emp, ans);
        size += cs;
    }
    ans[man] = size;
    return size + 1;
}

int main()
{
    int n;
    cin >> n;
    string ceo = "";
    unordered_map<string, unordered_set<string>> hashMap;
    for (int i = 0; i < n; i++)
    {
        string emp, man;
        cin >> emp >> man;
        if (man == emp)
            ceo = man;
        hashMap[man].insert(emp);
    }
    map<string, int> ans;
    count(hashMap, ceo, ans);
    for (auto emp : ans)
    {
        cout << emp.first << " " << emp.second << endl;
    }
    return 0;
}