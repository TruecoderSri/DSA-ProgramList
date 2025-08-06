

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int low = 0;
        int high = height.size() - 1;
        int maxi = 0;
        while (low < high)
        {
            int area;
            if (height[low] < height[high])
            {
                area = height[low] * (high - low);
                low++;
            }
            else
            {
                area = height[high] * (high - low);
                high--;
            }
            if (area > maxi)
                maxi = area;
        }
        return maxi;
    }
};