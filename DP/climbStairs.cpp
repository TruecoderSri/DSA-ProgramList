class Solution
{
public:
    int climbStairs(int n)
    {

        //  reaching at the dest itself can be done in 1 way n from n-1 also in 1 way
        int n1 = 1, n2 = 1;
        //  for corresponding values add the prev 2 values because moves're 1 or 2
        for (int i = n - 2; i >= 0; i--)
        {
            int temp = n1;
            n1 += n2;
            n2 = temp;
        }
        return n1;
    }
};