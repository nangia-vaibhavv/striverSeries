class Solution {
public:
	int pro(int i, int n, int buy, int fee ,vector<int>&v, vector<vector<int>>&dp)
	{
		if(i==n)    return 0;
		if(dp[i][buy]!=-1)  return dp[i][buy];
		int profit = 0;
		if(buy)
			profit = max((-v[i] - fee + pro(i+1,n,0,fee,v,dp)), pro(i+1,n,1,fee,v,dp));
		else
			profit = max((v[i] + pro(i+1,n,1,fee,v,dp)), pro(i+1,n,0,fee,v,dp));
		return dp[i][buy] = profit;
	}
	int maxProfit(vector<int>& v, int fee) {
		int n=v.size();
		vector<vector<int>>dp(n,vector<int>(2,-1));
		return pro(0,n,1,fee,v,dp);
	}
};