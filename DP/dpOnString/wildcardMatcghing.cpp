class Solution {
public:
    
    bool isMatch( string s, string p) {
        return helper(p,s);
    }
    
    
    bool helper( string s1, string s2){
        
       int n=s1.length(), m=s2.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        
        int i=1;
        while(i<=n && s1[i-1]=='*' ){
                dp[i][0]=1;
                i++;
        }
        dp[0][0]=1;
        
        for(int i=1 ; i<=n ; i++){
            for(int j=1 ; j<=m ; j++){
                if(s1[i-1]==s2[j-1] || s1[i-1]=='?')
                    dp[i][j]=dp[i-1][j-1];
                else if (s1[i-1]=='*')
                    dp[i][j]=dp[i-1][j] || dp[i][j-1];
            }
        }
        
        return dp[n][m];
        
        
    }
};