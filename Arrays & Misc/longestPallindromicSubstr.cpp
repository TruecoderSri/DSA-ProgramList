class Solution
{
public:
    string longestPalindrome(string s)
    {

        int l, r;
        int start = 0, end = 1;
        int n = s.size();
        for (int i = 1; i < n; i++)
        {

            //  for even string length or substr
            l = i - 1;
            r = i;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > end)
                {
                    end = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
            //   for odd string length or substr
            l = i - 1;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r])
            {
                if (r - l + 1 > end)
                {
                    end = r - l + 1;
                    start = l;
                }
                l--;
                r++;
            }
        }
        return s.substr(start, end);
    }
};