    int solve(int ind1,int ind2,string &s1, string &s2,vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
    if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        
//         match 
        if(s1[ind1]==s2[ind2])
        {
            return 1+solve(ind1-1, ind2-1, s1,s2,dp);
        }
//         not a match
        return dp[ind1][ind2]= max(solve(ind1-1,ind2,s1,s2,dp),solve(ind1,ind2-1,s1,s2,dp));
    }
int canYouMake(string &str, string &ptr)
{
    // Write your code here.
      int n=str.size();
        int m=ptr.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      return n+m-2* solve(n-1,m-1,str,ptr,dp);
}