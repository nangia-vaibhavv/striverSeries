int solve(int ind, int target, vector<int> &nums, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (target == 0 && nums[ind] == 0)
            return 2;
        if (target == 0 || nums[ind] == target)
            return 1;
        return 0;
    }
    if (dp[ind][target] != -1)
        return dp[ind][target];
    int nottake = solve(ind - 1, target, nums, dp);
    int take = 0;
    if (nums[ind] <= target)
        take = solve(ind - 1, target - nums[ind], nums, dp);
    return dp[ind][target] = take + nottake;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return solve(n - 1, tar, num, dp);
}