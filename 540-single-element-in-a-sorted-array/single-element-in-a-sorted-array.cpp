class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        //linear approach
        // int n=nums.size();
        // if(n==1) return nums[0];
        // for(int i=0;i<n-1;i+=2){
        //     if(nums[i]!=nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return nums[n-1];
        int n=nums.size();
        int start=0;
        int end=n-1;
        while(start < end){
            int mid = start + (end - start)/2;
            if(mid%2==0){
                if(nums[mid]==nums[mid+1]){
                    start = mid + 2;
                }else{
                    end = mid;
                }
            }else{
                if(nums[mid]==nums[mid-1]){
                    start = mid + 1;
                }else{
                    end = mid -1;
                }
            }
        }
        return nums[start];
    }
};