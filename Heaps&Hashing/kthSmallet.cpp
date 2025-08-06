class solution
{
public:
    int kthSmallest(int arr[], int l, int r, int k)
    {
        // code here
        // priority queue acts as the implementation of the max heap in STL lIBRARY
        priority_queue<int> pq(arr, arr + k);
        int n = r - l + 1;
        for (int i = k; i < n; i++)
        {
            if (arr[i] < pq.top())
            {
                pq.pop();
                pq.push(arr[i]);
            }
        }
        return pq.top();
    };