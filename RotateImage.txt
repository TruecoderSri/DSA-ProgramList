class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int n=arr.size();
        int m=arr[0].size();
        for(int i=0;i<n;i++){
            for(int j=i + 1;j<m;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<end){
                swap(arr[i][start],arr[i][end]);
                start++;
                end--;
            }
        }
    }
};