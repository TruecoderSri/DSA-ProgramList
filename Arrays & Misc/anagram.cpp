#include <iostream>
#include <vector>
using namespace std;
#define l 256
// Time complexity of O(n):Space Complexity of O(length of string)
bool isAnagram(string s, string t)
{
    int i;
    int count[l] = {0};
    for (i = 0; s[i] && t[i]; i++)
    {
        count[s[i]]++;
        count[t[i]]--;
    }
    if (s[i] != t[i])
        return false;
    for (i = 0; i < l; i++)

        if (count[i])
            return false;
    return true;
}
int main()
{
    string s = "listen";
    string t = "silent";
    if (isAnagram(s, t))

        cout << "the following pair is a anagram\n";
    else
        cout << "It is not a anagram\n";

    return 0;
}