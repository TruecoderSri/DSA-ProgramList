class Solution {
public:
# define mod 1000000007
int bit[100001];
int sum(int i){
    int ans=0;
    for(int j=i;j>0;j-=(j&-j)){
        ans+=bit[j];
    }
    return ans;
}

void update(int i){
    for(int j=i;j<=100001;j+=(j&-j)){
       bit[j]+=1;
    }

}
    int createSortedArray(vector<int>& v) {
        int n=v.size();
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=min(sum(v[i]-1),i-sum(v[i]));
            ans%=mod;
            update(v[i]);
        }
        return ans;
    }
};