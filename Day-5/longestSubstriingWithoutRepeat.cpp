class Solution {
public:
    int lengthOfLongestSubstring(string s) {
                  
        int n = s.length();
        
        // track index position of chars
        int pos_track[512];
        memset(pos_track,-1,512*sizeof(int));
        
        // result max length substring
        int result  = 0;
        
        // first ppointer of the window
        int first  = 0;
        // loop through string and check the valid substrings
        for(int last =0; last<n;last++)
        {
            // check if current window has last char in it 
            // if then we have to shrink the window as prev_pos current char + 1
            if(pos_track[s[last]]!=-1 && first<= pos_track[s[last]])
                first = pos_track[s[last]] + 1;
            
            // update result for max lenght valid substring 
            result = max(result, last-first+1);
            
            // store index position of the char s[last]
            pos_track[s[last]] = last; 
        }
        
        return result;
    }
};