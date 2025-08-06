#include <iostream>
#include <vector>
#include <map>
using namespace std;
string pallindrome(string s)
{
    string temp;
    int n = s.size();
    int i, j = n - 1, c;
    for (i = 0; i < n; i++)
    {
        if (s[i] != s[j])
        {
            j--;
        }
        else
        {
            c = j;
        }
    }
    for (i = 0; i < c; i++)
    {
        temp[i] = s[i];
    }
    return temp;
}
int main()
{
    string s = "BABAD";
    cout << pallindrome(s) << endl;
    return 0;
}