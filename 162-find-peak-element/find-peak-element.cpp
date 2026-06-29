class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //basic approach
        // int n=nums.size();
        // int mx=*max_element(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     if(nums[i]==mx){
        //         return i;
        //     }
        // }
        // return -1;
        //optimal approach
        int low = 0;
        int high = nums.size() - 1;
        while(low < high){
            int mid = low + (high - low)/2;
            if(nums[mid] < nums[mid + 1]){
                low = mid + 1;
            }
            else{
                high = mid;
            }
        }
        return low;
    }
};