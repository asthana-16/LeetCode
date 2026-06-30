class Solution {
public:
    bool canMake(vector<int>& bloomday,int m,int k,int day){
            int flowers=0;
            int bouquet=0;
            for(int i=0;i<bloomday.size();i++){
                if(bloomday[i]<=day){
                    flowers++;
                    if(flowers==k){
                        bouquet++;
                        flowers=0;
                    }
                }else{
                    flowers=0;
                }
            }
            return bouquet>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int start=0 , end= *max_element(bloomDay.begin(),bloomDay.end());
        int ans = - 1;
        while(start <= end){
            int mid = start + (end-start)/2;
            if(canMake(bloomDay,m,k,mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};