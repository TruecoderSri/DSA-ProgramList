#include <bits/stdc++.h>
// Time Complexity:O(N)
int kthSmallest(vector<int> &arr, int k)
{
    // Write your code here.
    int n = arr.size();
    int j = 0;
    int i = 1;
    int temp = 0;
    while (j < n && temp < k)
    {
        if (i == arr[j])
        {
            i++;
            j++;
        }
        else
        {
            temp++;
            i++;
        }
    }
    i--;
    while (temp < k)
    {
        temp++;
        i++;
    }
    return i;
}

// Better approach
// for(int i=0;i<n;i++){
//     if(arr[i]<=k)
//     k++;
//     else
//     break;
// }
// return k;
// }