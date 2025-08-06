#include <iostream>
using namespace std;
// sum of triplet less than a given sum
long long countTriplets(long long arr[], int n, long long sum)
{
    // Your code goes here
    sort(arr, arr + n);
    long long c = 0;
    for (int i = 0; i < n - 2; i++) // take three pointer in front ,second and last element and traverse while checking condns.
    {
        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            if ((arr[i] + arr[j] + arr[k]) < sum)
            {
                c += (k - j);
                // j++;
                j++;
            }
            else
            {

                k--;
            }
        }
    }
    return c;
}
int main()
{
    long long arr[] = {-2, 0, 1, 3};
    int sum = 2;
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << countTriplets(arr, n, sum) << endl;
    return 0;
}