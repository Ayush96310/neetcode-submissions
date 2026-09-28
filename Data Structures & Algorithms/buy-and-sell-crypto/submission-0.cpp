class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int curr = INT_MAX;
        for(int i=0; i<prices.size();i++){
            if(curr>prices[i]){
                curr = prices[i];
            }
            maxi = max(maxi,prices[i]-curr);
        }
        return maxi;
    }
};
