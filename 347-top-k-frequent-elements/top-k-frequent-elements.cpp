class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> count;
        for(int num:nums){
            count[num]++;
        }
        vector<vector<int>> freqbucket(n+1);
        for(auto& [num, freq] : count){
            freqbucket[freq].push_back(num);
        }
        vector<int> result;
        for(int i=n;i>=0;--i){
            for(int num:freqbucket[i]){
                result.push_back(num);
                if(result.size()==k){
                    return result;
                }
            }
        }
        return result;
    }
};