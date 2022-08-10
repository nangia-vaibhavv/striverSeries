#include<bits/stdc++.h>
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>&dp)
    {
                if(j<0 || j>=matrix[0].size()) return 1e8;

        if(i==0) return matrix[0][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int up=matrix[i][j]+solve(i-1,j,matrix,dp);
        int leftDiagonal=matrix[i][j]+solve(i-1,j-1,matrix,dp);
        int rightDiagonal=matrix[i][j]+solve(i-1,j+1,matrix,dp);
        return dp[i][j]= min(up, min(leftDiagonal,rightDiagonal));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int mini=1e8;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,solve(n-1,j,matrix,dp));
        }
        return mini;
        // return solve(n-1,j,matrix,dp);
    }
};