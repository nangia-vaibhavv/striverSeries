
class Solution
{
public:
    int solve(int ind, int buy, int cap, vector<int> &prices, int n, vector<vector<vector<int>>> &dp)
    {
        if (cap == 0)
            return 0;
        if (ind == n)
            return 0;
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        if (buy)
        {
            return dp[ind][buy][cap] = max(-prices[ind] + solve(ind + 1, 0, cap, prices, n, dp), solve(ind + 1, 1, cap, prices, n, dp));
        }
        else
            return dp[ind][buy][cap] = max(solve(ind + 1, 0, cap, prices, n, dp), prices[ind] + solve(ind + 1, 1, cap - 1, prices, n, dp));
    }
    int maxProfit(int k, vector<int> &prices)
    {
        int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
        // int cap = 2;
        // return solve(0, 1, 2, prices, n, dp);

        //         tabulation
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, 0)));
        for (int ind = n - 1; ind >= 0; ind--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int cap = 1; cap <= k; cap++)
                {
                    if (buy == 1)
                    {
                        dp[ind][buy][cap] = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
                    }
                    else
                        dp[ind][buy][cap] = max(dp[ind + 1][0][cap], prices[ind] + dp[ind + 1][1][cap - 1]);
                }
            }
        }
        return dp[0][1][k];
    }
};