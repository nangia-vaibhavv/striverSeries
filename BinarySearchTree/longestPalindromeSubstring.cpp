class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length(),l=1;
        if(n<2) return s;
        string ans="";
        ans+=s[0]; // A single Character is a Palindrome itself.
        
        for(int mid=0; mid<n; ++mid)
        {
            Palindrome(mid-1,mid,s,ans,l,n);  // To check for Even Palindrome
            Palindrome(mid-1,mid+1,s,ans,l,n);  // To check for Odd Palindrome
        }
        return ans;
    }
    void Palindrome(int i,int j,string &s, string &ans, int &l,int n)  // A function Check for even and odd palindrome
	// according to the  parameters pass into it.. Try to debug this part. You will get to Know how its working.
	//Take a Simple Example (String :- abaab)
    {
        while(i>=0 && j<n && s[i]==s[j])
        {
            if((j-i+1)>l)
            {
                ans=s.substr(i,j-i+1);
                l=j-i;
            }
            i--,j++;
        }
    }
};