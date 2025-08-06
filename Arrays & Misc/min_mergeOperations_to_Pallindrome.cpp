#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, i, ele, j, c = 0;
    cin >> n;
    vector<int> v1(n);
    for (i = 0; i < n; i++)
    {
        cin >> ele;
        v1.push_back(ele);
    }
    i = 0;
    j = n - 1;
    while (i <= j)
    {
        if (v1[i] == v1[j])
        {
            i++;
            j--;
        }
        if (v1[i] > v1[j])
        {
            v1[j] += v1[i];
            c++;
            j--;
        }
        else
        {
            v1[i] += v1[j];
            c++;
            i++;
        }
    }
    cout << "The number of operations for pallindorme:" << c << endl;
    return 0;
}