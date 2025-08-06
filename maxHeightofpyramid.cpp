#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int maxheightPyramid(int arr[], int n)
{

    int levels = 1; // to store the height of the maxheightPyramid
    int prev_count = 1;
    int prev_width = arr[0]; // store the width of the previous levels
    int curr_width = 0, curr_count = 0;

    sort(arr, arr + n);
    for (int i = 1; i < n; i++)
    {
        curr_width += arr[i];
        curr_count++;

        if (curr_width > prev_width && curr_count > prev_count)
        {
            prev_count = curr_count; // update the prev_width & prev_count
            prev_width = curr_width;

            // reset the values of curr to move to next level
            curr_width = 0;
            curr_count = 0;

            levels++;
        }
    }
    return levels;
}

int main()
{
    // code
    int arr[] = {40, 100, 30, 20};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxheightPyramid(arr, n) << endl;

    return 0;
}