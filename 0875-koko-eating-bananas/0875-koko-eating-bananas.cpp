class Solution {
public:
int findMax(vector<int>& piles){
    int maxi=INT_MIN;
    int n=piles.size();
    for(int i=0;i<n;i++){
        maxi=max(maxi,piles[i]);
    }
    return maxi;
}
    long long totalHrs(vector<int>& piles,int hourly){
        long long totalH=0;
        for(int i=0;i<piles.size();i++){
       totalH+=(1LL * piles[i]+hourly-1)/hourly;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=findMax(piles);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhours=totalHrs(piles,mid);
            if(totalhours<=h){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
        
    }
};