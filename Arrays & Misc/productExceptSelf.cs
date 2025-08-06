 #include <iostream>
 #include<vector.h>
using namespace std;
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n)
    {
         vector<long long int>ans;
        int countzero=0;
        long long int product=1,i;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0)
            countzero++;
            else
            product*=nums[i];
            
        }
        for(i=0;i<n;i++)
    {
        if(countzero>1)
        {
            ans.push_back(0);
        }
        else if(countzero==1)
        {
            if(nums[i]!=0)
            ans.push_back(0);
            else
            ans.push_back(product);
        }
        else if(countzero==0)
        {
            ans.push_back(product/nums[i]);
        }
    }
        return ans;
        
    }
    int main()
    {
        vector<long long int> nums;
        int i,ele;
        int n=nums.size;
        for(i=0;i<n;i++)
        {
            cin>ele;
            nums.push_back(ele);
        }
        vector<long long int> ans=productExceptSelf(nums,n);
        vector<long long int>::iterator itr;
        for(itr=ans.begin();itr!=ans.end();itr++)
        {
            cout<<*itr<<" ";
        }
        return 0;
    }