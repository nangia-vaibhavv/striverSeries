class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int profit=0, minElement=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            if(prices[i]<minElement)
            {
                minElement=prices[i];
            }
            if(prices[i]-minElement>profit)
            {
                profit=prices[i]-minElement;
            }
        }
        return profit;
    }
};