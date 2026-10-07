class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0; i<n;i++){
            int dis = pow(points[i][0],2)+pow(points[i][1],2);
            pq.push({dis,i});
        }
        vector<vector<int>> ans;
        for(int i=0; i<k;i++){
            auto [dis,ind] = pq.top();
            pq.pop();
            ans.push_back(points[ind]);
        }
        return ans;
    }
};
