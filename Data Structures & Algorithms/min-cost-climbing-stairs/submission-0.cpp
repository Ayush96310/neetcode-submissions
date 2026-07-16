class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> hash(n,0);
        hash[n-1]=cost[n-1];
        hash[n-2]=cost[n-2];

        for(int i=n-3; i>=0;i--){
            hash[i]=cost[i]+min(hash[i+1],hash[i+2]);
        }
        return min(hash[0],hash[1]);
    }
};
