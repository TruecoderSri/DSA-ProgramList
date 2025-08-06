#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int n, i;
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int product = 1;
    vector<int> output;
    for (i = 0; i < n; ++i)
    {
        product *= arr[i];
        output.push_back(product);
    }
    product = 1;
    for (i = n - 1; i > 0; --i)
    {
        output[i] = output[i - 1] * product;
        product *= arr[i];
    }
    output[0] = product;
    for (i = 0; i < output.size(); ++i)
        cout << output[i] << "\t";
    return 0;
}