#include <iostream>
#include <vector>
#include <string>
using namespace std;
#define l 256
void rep(char *s)
{
    int i;
    int *count = (int *)calloc(l, sizeof(int));
    for (i = 0; i < *(s + i); i++)
    {
        count[*(s + i)]++;
    }
    for (i = 0; i < l; i++)
    {
        if (count[i] > 1)
        {
            printf("%c,count=%d \n", i, count[i]);
        }

        free(count);
    }
}
int main()
{
    char s[] = "IloveRCBB";
    rep(s);
    return 0;
}