#include <iostream>
#include <string>
#include <vector>
using namespace std;
int longestReplacedString(string s, int k)
{
    int ans = 0, maxlen = 0;
    vector<int> count(26);
    int i, j = 0;
    for (i = 0; i < s.size(); i++)
    {
        count[s[i] - 'A']++;
        max = max(maxlen, count[s[i] - 'A']);
        if (j <= i && i - j + 1 > k)
        {
            count[s[j]]--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
int main()
{
    longest return 0;
}