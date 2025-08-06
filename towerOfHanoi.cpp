#include <iostream>
using namespace std;
// Time complexity O(2 ^ n - 1)
int towerHanoi(int n, char a, char b, char c)
{
    if (n == 0)
        return 0;
    towerHanoi(n - 1, a, c, b);
    cout << "Move disk " << n << " from rod " << a << " to rod " << c << endl;
    towerHanoi(n - 1, b, c, a);
}
int main()
{
    int n = 3;
    towerHanoi(n, 'a', 'b', 'c');
    return 0;
}