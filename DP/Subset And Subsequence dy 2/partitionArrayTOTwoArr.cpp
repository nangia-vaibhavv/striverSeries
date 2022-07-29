class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int totSum=0;
        for(int i=0;i<n;i++) totSum+=nums[i];
        
        int k=totSum;
    vector<vector<bool>>dp(n+1,vector<bool>(k+1,0));
    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }
        if(nums[0]<=k)
    dp[0][nums[0]]=true;
    for(int ind=1;ind<n;ind++)
    {
        for(int target=1;target<=k;target++)
        {
             bool nottake=dp[ind-1][target];
             bool take=false;
             if(nums[ind]<=target) take=dp[ind-1][target-nums[ind]];
            dp[ind][target]=take || nottake;
        }
    }
//         dp[n-1][0->totlaSum]
        int mini=1e9;
        for(int s1=0;s1<=totSum/2;s1++)
        {
            if(dp[n-1][s1]==true)
                mini=min(mini,abs((totSum-s1)-s1));
        }
    return mini;
    }
};