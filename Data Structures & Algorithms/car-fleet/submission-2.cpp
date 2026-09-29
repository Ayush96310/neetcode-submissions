class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        priority_queue<pair<int,int>> pq;
        int n = position.size();
        for(int i=0; i<n;i++){
            pq.push({position[i],speed[i]});
        }
        int ans = n;
        while(!pq.empty()){
            int pos = pq.top().first;
            int sp = pq.top().second;
            pq.pop();
            float time = (float)(target-pos)/sp;
            if(!pq.empty() && ((float)(target-pq.top().first)/pq.top().second)<=time){
                ans--;
                pq.pop();
                if(ans!=1) pq.push({pos,sp});
            }
        }
        return ans;
    }
};
