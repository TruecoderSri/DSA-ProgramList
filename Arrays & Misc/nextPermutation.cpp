#include <bits/stdc++.h>
using namespace std;
void reverse(int k, int l)
{
    vector<int> v;
    for (int i = v.size() - 1; i >= 0; i++)
    {
        cout << v[i];
    }
}
int main()
{
    vector<int> v;
    int n, ele;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the element: ";
        cin >> ele;
        v.push_back(ele);
    }
    int l = v.size(), j, k;
    vector<int>::iterator itr = v.begin();
    for (j = l - 2; j >= 0; j--)
    {
        if (v[j + 1] > v[j])
            break;
    }
    if (j < 0)
    {
        for (itr = v.end() - 1; itr >= v.begin(); itr--)

            cout << *itr << "\t";
    }
    else
    {
        for (k = n - 1; k > j; k--)
        {
            if (v[k] > v[j])
                break;
        }
        swap(v[j], v[k]);
        for (itr = v.end() - 1; itr <= v.begin() + k + 1; itr--)
        {
            cout << *itr << "\t";
        }
    }
    return 0;
}