class Solution {
public:
    int solve(int ind1, int ind2, string &s, string &t, vector<vector<int>>&dp)
    {
        if(ind1<0 || ind2<0)
        {
            return 0;
        }
         if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
//         match
        if(s[ind1]==t[ind2])return 1+ solve(ind1-1, ind2-1, s,t,dp);
        return dp[ind1][ind2]= max(solve(ind1-1,ind2,s,t,dp), solve(ind1,ind2-1,s,t,dp));
        
    }
    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(), t.end());
        int n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(n-1,n-1,s,t,dp);
    }
};