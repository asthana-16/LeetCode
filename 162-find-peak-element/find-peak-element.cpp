class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==mx){
                return i;
            }
        }
        return -1;
    }
};