#include <iostream>
using namespace std;
// brcket becomes dense when S=(X) format
int denseSequence(string s)
{
    int i = 0, ans = 0;
    int j = s.size() - 1;
    while (i <= j)
    {
        if (s[i] == '(' && s[j] == ')')
        {
            i++;
            j--;
        }
        else if (s[i] == ')' && s[j] == ')')
        {
            ans++;
            i++;
        }

        else if (s[i] == ')' && s[j] == '(')
        {
            i++;
            j--;
            ans += 2;
        }
        else
        {
            j--;
            ans++;
        }
    }
    return ans;
}
int main()
{
    string s = "((())))";
    cout << "dense sequence comes after removing " << denseSequence(s) << " bracket/s";
    return 0;
}