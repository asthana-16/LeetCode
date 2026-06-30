class Solution {
public:
    bool canPlace(vector<int>& position,int m,int dist){
        int balls=1;
        int last =position[0];
        for(int i=0;i<position.size();i++){
            if(position[i]-last>=dist){
                balls++;
                last=position[i];
            }
        }
        return balls>=m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int low = 1;
        int high = position.back()-position.front();
        int ans =0;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(canPlace(position,m,mid)){
                ans = mid;
                low = mid + 1;
            }else{
                high = mid - 1;
            }
        }
        return ans;
    }
};