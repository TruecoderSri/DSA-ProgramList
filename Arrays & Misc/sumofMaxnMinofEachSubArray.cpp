#include <bits/stdc++.h>
using namespace std;

int main()
{

    int arr[] = {2, 5, -1, 7, -3, -1, 2};
    int n = 7;
    int k = 4;
    int sum = 0;
    // storing the min and max of each subarray

    deque<int> sub_max;
    deque<int> sub_min;

    for (int i = 0; i < 7; i++)
    {
        // window checking conditions
        if (!sub_max.empty() && sub_max.front() == i - k)
            sub_max.pop_front();
        if (!sub_min.empty() && sub_min.front() == i - k)
            sub_min.pop_front();

        while (!sub_max.empty() && arr[i] > arr[sub_max.back()])
            sub_max.pop_back();
        while (!sub_min.empty() && arr[i] < arr[sub_min.back()])
            sub_min.pop_back();

        sub_max.push_back(i);
        sub_min.push_back(i);
        if (i >= k - 1)
        {
            cout << "min = " << arr[sub_min.front()] << " max =" << arr[sub_max.front()] << endl;
            sum += arr[sub_min.front()] + arr[sub_max.front()];
        }
    }
    cout << sum << endl;

    return 0;
}