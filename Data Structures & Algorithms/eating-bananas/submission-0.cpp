class Solution {
public:
    int hours(vector<int>& piles, int speed){
        int ans = 0;
        for(int i=0; i<piles.size();i++){
            ans+=(piles[i]+speed-1)/speed;
        }
        return ans;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = INT_MAX;
        while(low<=high){
            int mid = low + (high-low)/2;
            int timeTaken = hours(piles,mid);
            if(timeTaken<=h){
                high = mid-1;
                ans = min(ans,mid);
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
};
