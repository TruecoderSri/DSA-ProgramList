class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    static bool compare(Job j1, Job j2)
    {
        return (j1.profit > j2.profit);
    }
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,compare);
        int t=0;
        int jd=0, tprofit=0;
        //t=max deadline
        for(int i=0;i<n;i++) t=max(t,arr[i].dead);
        vector<int>slots(t,-1);
        //slots=all slots available for jobs
        //initially all are empty
        for(int i=0;i<n;i++){
            int d=arr[i].dead;
            for(int j=d-1;j>=0;j--){
                //if any slot before deadline is empty job can be done
                if(slots[j]==-1){
                    jd++;
                    tprofit+=arr[i].profit;
                    //fill the slot closest to deadline with job id
                    slots[j]=arr[i].id;
                    break;
                }
            }
        }
        vector<int>ans;
        ans.push_back(jd);
        ans.push_back(tprofit);
        return ans;
    } 
};
