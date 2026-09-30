class Solution {
public:
    int binary_search(vector<int>& arr, int low,int high, int target){
        while(low<=high){
            int mid = low+(high-low)/2;
            if(arr[mid]==target){
                return mid-1;
            }
            else if(arr[mid]>target){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        nums.push_back(INT_MAX);
        nums.insert(nums.begin(),INT_MAX);
        int n = nums.size();
        int low = 1;
        int high = n-2;
        int mini = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<nums[mid-1] && nums[mid]<nums[mid+1]){
                mini = mid;
                break;
            }
            else if(nums[mid]>nums[n-2]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        if(mini==-1) return binary_search(nums,1,n-2,target);
        if(target<=nums[n-2]){
            return binary_search(nums,mini,n-2,target);
        }
        return binary_search(nums,1,mini-1,target);
    }
};
