class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> mpp;
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        mpp[key].push_back({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        vector<pair<int,string>>& arr = mpp[key];
        int n = arr.size();
        if(n==0 || timestamp<arr[0].first) return "";
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid].first==timestamp){
                return arr[mid].second;
            }
            else if(arr[mid].first>timestamp){
                if(mid==0) return "";
                if(arr[mid-1].first<timestamp){
                    return arr[mid-1].second;
                }
                high = mid-1;
            }
            else{
                if(mid==n-1 || arr[mid+1].first>timestamp){
                    return arr[mid].second;
                }
                low = mid+1;
            }
        }
        return "";
    }
};
