#include <iostream>
#include <unordered_map>
using namespace std;
void commonele(int a[], int b[], int c[], int n1, int n2, int n3)
{
    int i, temp[] = {0};
    unordered_map<int, int> m1, m2, m3;
    int co = 0;
    for (i = 0; i < n1; i++)
    {
        m1[a[i]]++;
    }

    for (i = 0; i < n2; i++)
    {
        m2[b[i]]++;
    }
    for (i = 0; i < n3; i++)
    {
        m3[c[i]]++;
    }
    for (i = 0; i < n1; i++)
    {

        if (m1[a[i]] > 0 && m2[a[i]] > 0 && m3[a[i]] > 0)
        {
            temp[i] = a[i];
            m1[a[i]] = 0;
            co++;
        }
    }
    for (i = 0; i < co; i++) // make a vector instead coz it wll printonly single characters
    {
        cout << temp[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a[] = {1, 5, 10, 20, 40, 80};
    int n1 = sizeof(a) / sizeof(a[0]);

    int b[] = {6, 7, 20, 80, 100};
    int n2 = sizeof(b) / sizeof(b[0]);

    int c[] = {3, 4, 15, 20, 30, 70, 80, 120};
    int n3 = sizeof(c) / sizeof(c[0]);
    // int n = min(min(p, q), s);
    commonele(a, b, c, n1, n2, n3);
    return 0;
}