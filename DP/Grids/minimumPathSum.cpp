class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(); 
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(i==0 && j==0) dp[i][j]=grid[i][j];
                else{
                    int left=grid[i][j];
                    if(j>0)left+=dp[i][j-1];else left+=1e9;

                    int up=grid[i][j];
                    if(i>0)up+=dp[i-1][j]; else up+=1e9;

                    dp[i][j]=min(left,up);
                }
            }
        }
        return dp[n-1][m-1];
//         int m=grid.size();
// int n=grid[0].size();
// vector<vector<int>>dp(m,vector<int>(n,0));
// for(int i=0;i<m;i++)
// {
// for(int j=0;j<n;j++)
// {
// if(i==0 && j==0) dp[i][j]=grid[i][j];
// else{
// int up=grid[i][j];
// if(i>0) up+=dp[i-1][j];
// else up+=1e9;
// int left=grid[i][j];
// if(j>0) left+=dp[i][j-1];
// else left+=1e9;

// dp[i][j]=min(up,left);
// }
// }
// }
// return dp[m-1][n-1];
    }
};