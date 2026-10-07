class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char,int> mpp;
        for(int i=0; i<m;i++){
            mpp[tasks[i]]++;
        }
        priority_queue<int> pq;
        for(auto t:mpp){
            pq.push(t.second);
        }
        int maxi = pq.top();
        int cnt = 0;
        int others = 0;
        while(!pq.empty()){
            if(pq.top()==maxi){
                cnt++;
            }
            else{
                others+=pq.top();
            }
            pq.pop();
        }
        // if(cnt>n+1){
        //     return others+(maxi)*(n+1)+maxi*(cnt-n-1);
        // }
        return (maxi-1)*(n+1)+cnt+max(others-(maxi-1)*(n+1-cnt),0);
    }
};
