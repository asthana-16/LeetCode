class Solution {
public:
    int findMin(vector<int>& nums) {
        //normal basic approach
        int n=nums.size();
        // int min=nums[0];
        // for(int i=0;i<n;i++){
        //     if(nums[i]<=min){
        //         min = nums[i];
        //     }
        // }
        // return min;
        //O(lon n) approach
        int start=0;
        int end=n-1;
        while(start < end){
            int mid = (start+end)/2;
            if(nums[mid]<nums[end]){
                end = mid;
            }
            else{
                start = mid+1;
            }
        }
        return nums[start];
    }
};