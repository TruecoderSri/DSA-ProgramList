#include <iostream>
#include <string.h>
using namespace std;
int subsequence(string p, string output[])
{
    if (p.length() == 1)
    {
        output[0] = " ";
        return 1;
    }
    int siz = subsequence(p.substr(1), output);
    for (int i = 0; i < siz; i++)
    {
        output[i + siz] = output[i] + p[0];
    }
    return (2 * siz);
}
int main()
{
    string output[1000];
    int a = subsequence("ab", output);
    for (int i = 0; i < a; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}