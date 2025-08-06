#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int mycompare(string x, string y)
{
    string xy = x.append(y);
    string yx = y.append(x);
    return xy.compare(yx) > 0 ? 1 : 0;
}
void print(vector<string> &v)
{
    sort(v.begin(), v.end(), mycompare);
    cout << "The largest no which can we formed is:";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i];
    }
    cout << endl;
}
int main()
{
    vector<string> v;
    int n, i, ele;
    cin >> n;
    v.push_back("54");
    v.push_back("546");
    v.push_back("548");
    v.push_back("60");

    print(v);
    return 0;
}
