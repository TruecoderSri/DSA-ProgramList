	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    int maxsum[n];
	    for(int i=0;i<n;i++){
	        maxsum[i]=arr[i]; //initialised with the min possible sum
	    }
	    for(int i=1;i<n;i++){
	        for(int j=0;j<i;j++){
	            if(arr[i]>arr[j]&&maxsum[i]<maxsum[j]+arr[i])
	            maxsum[i]=maxsum[j]+arr[i];
	        }
	    }
	    int ans=0;
	    for(int i=0;i<n;i++){
	        ans=max(ans,maxsum[i]);
	    }
	    return ans;
	    
	}  