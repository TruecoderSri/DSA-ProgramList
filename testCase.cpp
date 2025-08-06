#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;
int main()
{
    string s;
    int rev[1000], d[1000], diff[1000], i, l = 0, flag;
    cin >> s;
    for (i = 0; s[i] != '\0'; i++)
    {
        l++;
    }
    for (i = 0; i < l; i++)
    {
        d[i] = s[i];
        cout << d[i] << "\t";
    }
    cout << endl;
    for (i = 0; i < l - 1; i++)
    {
        diff[i] = abs(d[i + 1] - d[i]);
    }

    for (i = 0; i < l; i++)
    {
        rev[i] = diff[l - i - 1];
    }
    for (i = 0; i < l; i++)
    {
        cout << rev[i] << "\t";
    }
    for (i = 0; i < l; i++)
    {
        if (diff[i] != rev[i])
            flag = 1;
        else
            flag = 0;
    }
    if (flag == 1)
    {
        cout << "Not Funny\n ";
    }
    else
        cout << " Funny";

    return 0;
}