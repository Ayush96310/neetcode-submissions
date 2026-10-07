class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==1) return stones[0];
        priority_queue<int> pq;
        for(int i=0; i<n;i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int ans = first-second;
            if(ans) pq.push(ans);
        }
        if(pq.empty()) return 0;
        return pq.top();
    }
};
