#define MOD 1000000007        //change the value if reqd.

int countWays(int index, vector<int> &nums, int target, vector<vector<int>>& dp)
{
    if(index<0)
    {
        if(target == 0)
        {
            return 1;
        }
        else 
        {
            return 0;
        }
    }
    
    if(dp[index][target] != -1)    return dp[index][target];
    
    int way1=0, way2=0;
    //The if condition check is necessary to prevent array index out of bounds!
    if(target-nums[index] >= 0)
        way1 = countWays(index-1, nums, target-nums[index], dp);
    way2 = countWays(index-1, nums, target, dp);
    
    return dp[index][target] = (way1 + way2)%MOD;
}

int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return countWays(num.size()-1, num, tar, dp);
}

int countPartitions(int n, int d, vector<int> &arr) {
    int total = 0;
    for(auto &it: arr)    total+=it;
    
    if(total - d < 0 or (total - d)%2)    return 0;
    
    return findWays(arr, (total-d)/2);
}