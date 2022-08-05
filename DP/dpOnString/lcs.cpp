// // time (2^n+2^m)
// class Solution {
// public:
//     int solve(int ind1,int ind2,string s1, string s2)
//     {
//         if(ind1<0 || ind2<0)
//         {
//             return 0;
//         }
// //         match 
//         if(s1[ind1]==s2[ind2])
//         {
//             return 1+solve(ind1-1, ind2-1, s1,s2);
//         }
// //         not a match
//         return max(solve(ind1-1,ind2,s1,s2),solve(ind1,ind2-1,s1,s2));
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//           int n=text1.size();
//         int m=text2.size();
//       return  solve(n-1,m-1,text1,text2);
//     }
// };


// memoization  O)(n*m) space O(n*m)+O(n+m)
class Solution {
public:
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
    int longestCommonSubsequence(string text1, string text2) {
          int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
      return  solve(n-1,m-1,text1,text2,dp);
    }
};