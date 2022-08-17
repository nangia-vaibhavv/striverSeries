bool comp(string &a,string &b){
    return a.size()<b.size();
}

class Solution {
public:
    
    bool check(string &a,string &b){
        if(a.size()!=b.size()-1) return false;
        int i=0,j=0;
        int m=a.size(),n=b.size();
        while(i<m and j<n){
            if(a[i]!=b[j]) j++;
            else i++,j++;
        }
        return (i==m);
    }
    
    int longestStrChain(vector<string>& words) {
        
        int n=words.size();
        
        sort(words.begin(),words.end(),comp);
        
        int dp[n];
        
        for(int i=0;i<n;i++){
            dp[i]=1;
            for(int j=i-1;j>=0;j--){
                if(check(words[j],words[i]))
                    dp[i]=max(dp[i],1+dp[j]);   
            }
        }
        
        return *max_element(dp,dp+n);
    }
};