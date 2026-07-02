class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int totalones=0 , windowones = 0, maxones = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                totalones++;
            }
        }
        maxones = windowones;
        for(int i=0;i<totalones;i++){
            if(nums[i] == 1) windowones++;
        }
        for(int i=totalones;i<n+totalones;i++){
            windowones -= nums[(i-totalones)%n];
            windowones += nums[i%n];
            maxones = max(maxones, windowones);
        }
        return totalones - maxones;
    }
};