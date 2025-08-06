#include <iostream>
#include <vector>
#include <string>
using namespace std;
vector<int> fact, digits;
void solve(string &ans, int n, int k)
{
    if (n == 1)
    {
        ans += to_string(digits.back());
        return;
    }
    int index = k / fact[n - 1];
    if (k % fact[n - 1] == 0)
        index -= 1;
    ans += to_string(digits[index]);
    digits.erase(digits.begin() + index);
    k -= fact[n - 1] * index;
    solve(ans, n - 1, k);
}
string getpermutation(int n, int k)
{
    fact.push_back(1);
    int f = 1;
    for (int i = 0; i < n; i++)
    {
        f = f * i;
        fact.push_back(f);
    }
    for (int i = 0; i <= n; i++)
    {
        digits.push_back((i));
    }
    string ans = "";
    solve(ans, n, k);
    return ans;
}
int main()
{

    string ans = getpermutation(4, 12);
    solve(ans, 4, 12);
    for (int i = 0; ans[i] != '\0'; i++)
    {
        cout << ans[i];
    }
    return 0;
}