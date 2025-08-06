#include <bits/stdc++.h>
using namespace std;
// tIME COMPLEXITY:o()
int getmax(int job[], int n)
{
    int result = job[0];
    for (int i = 1; i < n; i++)
    {
        if (job[i] > result)
        {
            result = job[i];
        }
    }
    return result;
}
// here 'time' refers to the mid value passed from the array in the below function
bool ispossible(int time, int k, int job[], int n)
{
    int count = 1;
    int curr_time = 0;

    for (int i = 0; i < n;)
    {
        if ((curr_time + job[i]) > time)
        {
            curr_time = 0;
            count++;
        }
        else
        {
            curr_time += job[i];
            i++;
        }
    }
    return (count <= k);
}

int getmintime(int k, int T, int job[], int n)
{
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {
        end += job[i];
    }
    int ans = end;
    int maxjob = getmax(job, n);
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (mid >= maxjob && ispossible(mid, k, job, n))
        {
            ans = min(ans, mid);
            end = mid - 1;
        }
        else
        {
            start = end + 1;
        }
    }
    return (ans * T);
}

int main()

{
    int job[] = {4, 5, 10};
    int n = sizeof(job) / sizeof(job[0]);
    int k = 2, T = 5;
    cout << getmintime(k, T, job, n);
    return 0;
}