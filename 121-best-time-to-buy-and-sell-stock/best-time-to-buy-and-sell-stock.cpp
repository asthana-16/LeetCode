class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // int minprice=prices[0];
        // int maxprofit=0;
        // for(int i=0;i<prices.size();i++){
        //     minprice=min(minprice,prices[i]);
        //     int profit=prices[i]-minprice;
        //     maxprofit=max(maxprofit,profit);
        // }
        // return maxprofit;
        int buy=0;
        int profit=0;
        int maxprofit=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]<prices[buy]){
                buy=i;
            }
            if(prices[i]>prices[buy]){
                profit=prices[i]-prices[buy];
                maxprofit=max(maxprofit,profit);
            }
        }
        return maxprofit;
    }
};
