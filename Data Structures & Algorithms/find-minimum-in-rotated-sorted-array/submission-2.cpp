class Solution {
public:
    int findMin(vector<int> &nums) {
        nums.push_back(INT_MAX);
        nums.insert(nums.begin(),INT_MAX);
        int n = nums.size();
        int low = 1;
        int high = n-2;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid]<nums[mid+1] && nums[mid]<nums[mid-1]){
                return nums[mid];
            }
            else if (nums[mid]>nums[n-2]){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return -1;
    }
};
