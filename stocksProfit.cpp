#include <iostream>
#include <vector>
using namespace std;
int main()
{
    vector<int> prices;
    int n, ele;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "enter the element: ";
        cin >> ele;
        prices.push_back(ele);
    }
    int i, min = prices[0];
    int profit = 0;
    for (i = 0; i < prices.size(); i++)
    {
        if (prices[i] < min)
        {
            min = prices[i];
        }
        else if (prices[i] - min > profit)
            profit = prices[i] - min;
    }
    cout << "\n MAX profit is:"
         << profit << endl;

    return 0;
}