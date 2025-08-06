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
        maxlen = max(maxlen, count[s[i] - 'A']);
        if (j <= i && (i - j + 1) - maxlen > k)
        {
            count[s[j] - 'A']--;
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    return ans;
}
int main()
{
    cout << longestReplacedString("ABCA", 3);
    return 0;
}