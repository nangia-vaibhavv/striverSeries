// class Solution {
// public:
//     bool f(int ind, int target, vector<int>&arr,vector<vector<int>>&dp)
// {
//     if(target==0) return true;
//     if(ind==0) return (arr[0]==target);
//     if(dp[ind][target]!=-1)return dp[ind][target];
//     bool notTake=f(ind-1,target,arr,dp);
//     bool take=false;
//     if(arr[ind]<=target)take=f(ind-1,target-arr[ind],arr,dp);
    
//     return dp[ind][target]= take || notTake;
// }
//     bool subsetSumToK(int n, int k, vector<int> &arr) {
//     // Write your code here.
//     vector<vector<int>>dp(n, vector<int>(k+1,-1));
//     return f(n-1,k,arr,dp);
// }
//     bool canPartition(vector<int>& nums) {
//         int n=nums.size();
//         int totsum=0;
//         for(int i=0;i<n;i++)
//         {
//             totsum+=nums[i];
//         }
//         if(totsum%2) return false;

//         int target=totsum/2;
//         return subsetSumToK(n,target,nums);
            
        
//     }
// };
class Solution {
public:
    bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
        if(arr[0]<=k)
    dp[0][arr[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
             bool nottake=dp[ind-1][target];
             bool take=false;
             if(arr[ind]<=target) take=dp[ind-1][target-arr[ind]];
            dp[ind][target]=take || nottake;
        }
    }
    return dp[n-1][k];
}


    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2!=0) return false;
        int target=sum/2;
        // if(subsetSumToK(n,target,nums)){
        //     return true;
        // }
        // return false;
        return subsetSumToK(n,target,nums);
    }
};

