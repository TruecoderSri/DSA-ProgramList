#include <iostream>
#include <string>
#include <vector>
using namespace std;
int lengthOfLongestSubstring(string s)
{
    int l = 0;
    vector<int> arr(256, -1);
    int start = -1, maxlen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (arr[s[i]] > start)
            start = arr[s[i]];
        arr[s[i]] = i;
        maxlen = max(maxlen, i - start);
    }
    return maxlen;
}
int main()
{
    string s = "comeBackStrong";
    cout << "max substring length:" << lengthOfLongestSubstring(s);
    return 0;
}