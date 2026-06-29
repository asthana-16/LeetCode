class Solution {
public:
    bool search(vector<int>& nums, int target) {
        //basic approach
        int n=nums.size();
        // for(int i=0;i<n;i++){
        //     if(nums[i]==target) return true;
        // }
        // return false;
        //Binary Search
        int start = 0; 
        int end = n-1;
        while(start <= end){
            int mid = (start+end)/2;
            if(nums[mid]==target) return true;
            else if(nums[start]==nums[mid] && nums[mid] == nums[end]){
                start++;
                end--;
                continue;
            }
            else if(nums[start] <= nums[mid]){
                if (target >= nums[start] &&
                    target < nums[mid])

                    end = mid - 1;

                else
                    start = mid + 1;
            }
            else{
                if (target > nums[mid] &&
                    target <= nums[end])

                    start = mid + 1;

                else
                    end = mid - 1;
            }
        }
        return false;
    }
};