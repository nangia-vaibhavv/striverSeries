int helper(vector<int> &price, int ind,int n,vector<vector<int>>&dp){
    if(ind==0){
        return n*price[0];
    }
    if(dp[ind][n]!=-1) return dp[ind][n];
    int notTake=helper(price,ind-1,n,dp);
    int take=INT_MIN;
    int rodLength=ind+1;
    if(rodLength<=n) take=price[ind]+helper(price,ind,n-rodLength,dp);
    return dp[ind][n]= max(take,notTake);
    
}
int cutRod(vector<int> &price, int n)
{
    // Write your code here
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return helper(price,n-1,n,dp);
}