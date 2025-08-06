int minJumps(int arr[], int n){
        // Your code here
        
         //if number of element is 1/0 then its already at the end so
        if(n<=1)
        return 0;
        if(arr[0]==0)
        return -1;
        
        int steps=arr[0];
        int maxStep=arr[0];
        int jumps=1;
        for(int i=1;i<n;i++){
            if(i==n-1)
            return jumps;
            
            maxStep=max(maxStep,i+arr[i]);
            steps--;
            if(steps==0){
                jumps++;
                if(i>=maxStep)
                return -1;
                steps=maxStep-i;
            }
        }
        return -1;
    }