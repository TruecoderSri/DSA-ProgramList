Optimized Approach

class Solution {
public:

    //    Time Compexity :O(N1)
    //    Space Complexity:O(1)

    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int n1=a.size();
        int n2=b.size();

        // ensuring n1 remains smaller
        if(n1>n2) return findMedianSortedArrays(b,a);

        // applyng Binary Search on the smaller array

        int low=0,high=n1;
        int left=(n1+n2+1)/2;
        int n=n1+n2;
        while(low<=high){
            int mid1=(low+high)>>1;
            int mid2=left-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;

            if(mid1<n1) r1=a[mid1];
            if(mid2<n2) r2=b[mid2];

            if(mid1-1>=0) l1=a[mid1-1];
            if(mid2-1>=0) l2=b[mid2-1];

            if(l1<=r2 && l2<=r1){
                if(n%2==1) return max(l1,l2);
                else
                return double((max(l1,l2)+min(r1,r2))/2.0);
            }
            else if(l1>r2) high=mid1-1;
            else low=mid1+1;

        }
        return 0;
    }
};

xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx



#include <iostream>
#include <climits>
using namespace std;
// find the median of the 2 arrays of diff sizes when merged
// Time complexity : O(min(n1, n2))
double findMedian(int a[], int b[], int n1, int n2)
{
    // basically we apply binary search on the smaller array to get lower time complexity
    if (n2 < n1)
        return findMedian(b, a, n1, n2);
    int low = 0;
    int high;
    n1 < n2 ? high = n1 : high = n2;
    while (low <= high)
    {
        int cut1 = (low + high / 2);
        int cut2 = ((n1 + n2 + 1) / 2) - cut1;
        // dividing the 2 arrays into 4 parts based on the given condn.
        int l1 = cut1 == 0 ? INT_MIN : a[cut1 - 1]; // l1 and r1 are div in first array
        int l2 = cut2 == 0 ? INT_MIN : b[cut2 - 1]; // l2 and r2 are div in the second array

        int r1 = cut1 == n1 ? INT_MAX : a[cut1];
        int r2 = cut2 == n2 ? INT_MAX : b[cut2];
        // until condn. is satisfied
        if ((l1 <= r2) && (l2 <= r1))
        {
            if ((n1 + n2) % 2 == 0)
                return (double(min(r1, r2) + max(l1, l2)) / 2);
            else
                return max(l1, l2);
        }
        // i.e. the cut1 is shifted to the left
        else if (l1 > r2)
        {
            high = cut1 - 1;
        }
        // the cut1 is shifted to the right
        else
        {
            low = cut1 + 1;
        }
    }
    return 0;
}
int main()
{
    int a[] = {-5, 3, 6, 12, 15};
    int b[] = {-12, -10, -6, -3, 4, 10};
    int n1 = sizeof(a) / sizeof(a[0]);
    int n2 = sizeof(b) / sizeof(b[0]);
    double median = findMedian(a, b, n1, n2);
    cout << "median of the above data: " << median << endl;
    return 0;
}