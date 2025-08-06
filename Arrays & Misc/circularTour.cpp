//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)
struct petrolPump
{
    int petrol;
    int distance;
};

// } Driver Code Ends
/*
The structure of petrolPump is
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution
{
public:
    // Function to find starting point where the truck can start to get through
    // the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[], int n)
    {
        // Your code here
        int front = 0;
        int end = 1;

        int curr_petrol = p[front].petrol - p[front].distance;

        while (front != end || curr_petrol < 0)
        {

            while (curr_petrol < 0 && front != end)
            {
                curr_petrol -= p[front].petrol - p[front].distance;
                front = (front + 1) % n;

                if (front == 0)
                    return -1;
            }
            curr_petrol += p[end].petrol - p[end].distance;
            end = (end + 1) % n;
        }
        return front;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        petrolPump p[n];
        for (int i = 0; i < n; i++)
            cin >> p[i].petrol >> p[i].distance;
        Solution obj;
        cout << obj.tour(p, n) << endl;
    }
}

// } Driver Code Ends