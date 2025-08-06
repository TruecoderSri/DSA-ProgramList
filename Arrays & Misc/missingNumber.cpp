class Solution
{
    public:
    //Function to find the smallest positive number missing from the array.
    int missingNumber(int arr[], int n) 
    { 
        // Your code here
        
        sort(arr,arr+n);
        
        for(int i=0;i<n;i++){
           if(arr[i]>0){
               if(arr[i]!=1) return 1;
               for(int j=i+1;j<n;j++,i++){
                   if((arr[j]-arr[i])>1)
                   return arr[i]+1;
               }
               return arr[n-1]+1;
           }
           
        }
        return 1;
    } 
};