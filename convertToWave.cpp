#include <iostream>
#include <vector>
using namespace std;
void convertToWave(int n, vector<int> &arr)
{

    // Your code here
    int i, j;
    for (i = 0; i < n - 1; i += 2)
    {
        if (i + 1 < n)
        {
            int temp = arr[i];
            arr[i] = arr[i + 1];
            arr[i + 1] = temp;
        }
    }
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
int main()
{
    vector<int> arr = {1, 3, 5, 6, 8, 9};
    int n = arr.size();
    convertToWave(n, arr);
    return 0;
}