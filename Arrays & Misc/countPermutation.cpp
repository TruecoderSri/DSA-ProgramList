#include <bits/stdc++.h>
using namespace std;
// to count the numbers whose permutations are greater than the given number
// Time Complexity:O(n)
int countpermutations(int n)
{
    stack<int> st;
    int count = 0, i;
    for (i = 1; i <= 9; i++)
    {
        if (i <= n)
        {
            st.push(i);
            count++;
        }

        while (!st.empty())
        {
            int a = st.top();
            st.pop();
            for (int j = a % 10; j <= 9; j++)
            {
                int ans = a * 10 + j;

                if (ans <= n)
                {
                    st.push(ans);
                    count++;
                }
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int ans = countpermutations(n);
    cout << ans << endl;
    return 0;
}