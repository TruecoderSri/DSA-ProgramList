#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Function to find all divisors of n
vector<int> findDivisors(int n)
{
    vector<int> divisors;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            divisors.push_back(i);
        }
    }
    return divisors;
}

// Function to calculate the minimum number of steps to make the string K-switching
int minStepsToKSwitching(int N, const string &S)
{
    vector<int> factors = findDivisors(N);
    int minSteps = INT_MAX;

    // Check each factor
    for (int K : factors)
    {
        int steps = 0;
        for (int i = 0; i < N; i++)
        {
            if ((i / K) % 2 == 0)
            {
                if (S[i] != '0')
                {
                    steps++;
                }
            }
            else
            {
                if (S[i] != '1')
                {
                    steps++;
                }
            }
        }
        minSteps = min(minSteps, steps);
    }

    return minSteps;
}

int main()
{
    int N;
    string S;

    cin >> N;
    cin >> S;

    int result = minStepsToKSwitching(N, S);
    cout << result << endl;

    return 0;
}
