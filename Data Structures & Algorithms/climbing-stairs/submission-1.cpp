class Solution {
public:
    int climbStairs(int n) {
        if(n==1) return 1;
        if(n==2) return 2;
        vector<int> hash(n,0);
        hash[n-1]=1;
        hash[n-2]=2;
        for(int i=n-3; i>=0; i--){
            hash[i]=hash[i+1]+hash[i+2];
        }
        return hash[0];
    }
};
