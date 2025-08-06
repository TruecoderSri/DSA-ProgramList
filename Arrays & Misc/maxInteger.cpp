
//   Given n integer ranges, the task is to return the maximum occurring integer in the given ranges.
// If more than one such integer exists, return the smallest one.
// The ranges are in two arrays l[] and r[].  l[i] consists of the starting point of the range and r[i] consists of the corresponding endpoint of the range & a
// maxx which is the maximum value of r[].

TC : O(N)

         int maxOccured(int n, int l[], int r[], int maxx)
{

    // Your code here
    vector<int> buff(maxx + 2, 0);

    for (int i = 0; i < n; i++)
    {
        buff[l[i]]++;
        buff[r[i] + 1]--;
    }
    int sum = 0;

    for (int i = 0; i <= maxx + 1; i++)
    {
        buff[i] += sum;
        sum = buff[i];
    }
    int ans = 0;
    for (int i = 1; i <= maxx; i++)
    {
        if (buff[i] > buff[ans])
        {
            ans = i;
        }
    }
    return ans;
}
