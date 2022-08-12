class Solution {
public:
    int mod= 1e9+7;
int solve(int ind, int sum,vector<int>&num,vector<vector<int>>&dp)
    {
//         if(sum==0)  return 1;
        if(ind==0)
        {
            if(sum==0 && num[0]==0 )return 2;
            if(sum==0 || sum==num[0]) return 1;
            return 0;
        }
//             return num[0]==sum;
        if(dp[ind][sum]!=-1) return dp[ind][sum];
        int nottake=solve(ind-1,sum,num,dp);
        int take=0;
        if(num[ind]<=sum)
            take=solve(ind-1,sum-num[ind],num,dp);
        return dp[ind] [sum]=take+nottake;
    }
int findWays(vector<int>&nums,int tar)
{
    int n=nums.size();
    vector<vector<int>>dp(n,vector<int>(tar+1,-1));
    return solve(n-1,tar,nums,dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int h=arr.size();
    int totSum=0;
    for(int i=0;i<h;i++)
    {
        totSum+=arr[i];
    }
     if(totSum-d<0 || (totSum-d)%2)return false;
        return findWays(arr,(totSum-d)/2);
}



    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countPartitions(n,target,nums);
    }
};