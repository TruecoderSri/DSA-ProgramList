#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
// Time complexity of O(N * N!)and space complexity of O(N)
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int permute(char *s, int l, int r)
{
    int c = 0;
    if (l == r)
    {
        cout << s << "\t";
        c++;
    }
    else
        for (int i = l; i <= r; i++)
        {
            swap(s + l, s + i);
            permute(s, l + 1, r);
            swap(s + l, s + i);
        }
    return c;
}
int main()
{
    char str[] = "ABCD";
    int n = strlen(str);
    cout << permute(str, 0, n - 1);
    return 0;
}