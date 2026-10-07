class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int target;
    KthLargest(int k, vector<int>& nums) {
        target = k;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        for(int i=0; i<n-k;i++){
            pq.pop();
        }
    }
    
    int add(int val) {
        if(pq.size()<target){
            pq.push(val);
        }
        else if(val>=pq.top()){
            pq.push(val);
            pq.pop();
        }
        return pq.top();
    }
};
