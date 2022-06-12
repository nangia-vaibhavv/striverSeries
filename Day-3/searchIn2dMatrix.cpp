
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      
    // int n=matrix.size();
    //     int m=matrix[0].size();
    //     int low=0, high=n-1;
    //  while(low<=high)
    //  {
    //      int mid=low+(high-low)/2;
    //      if(matrix[mid][0]==target) return true;
    //      if(matrix[mid][m-1]==target) return true;
    //       if(target>matrix[mid][0] && target<matrix[mid][m-1])
    //      {
    //          int s=0, e=m-1;
    //          while(s<=e)
    //          {
    //              int mid1=s+(e-s)/2;
    //              if(matrix[mid][mid1]==target) return true;
    //              else if(target<matrix[mid][mid1])
    //              {
    //                  e=mid1-1;
    //              }
    //              else s=mid+1;
    //          }
    //      }
    //      if(target<matrix[mid][0])
    //      {
    //          high=mid-1;
    //      }
    //      if(target>matrix[mid][mid-1])
    //      {
    //          low=mid+1;
    //      }
    //  }
    //     return false;
    // }

                int n=matrix.size();
        int m=matrix[0].size();
        int low=0, high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(matrix[mid][0]==target) return true;
             if(matrix[mid][m-1]==target) return true;
             if(target>matrix[mid][0] && target<matrix[mid][m-1]) {
//                 apply binary search here
                int si=0, ei=m-1;
                while(si<=ei)
                {
                    int mid1=si+(ei-si)/2;
                    if(matrix[mid][mid1]==target)
                        return true;
                    else if(matrix[mid][mid1]<target)
                    {
                        si=mid1+1;
                    }
                    else ei=mid1-1;
                }
            }
             if(target<matrix[mid][0])
            {
//                 apply binary search
                high=mid-1;
            }
             if(target>matrix[mid][mid-1])
            {
//                 apply binary search
                low=mid+1;
            }
        }
        return false;
    }
       //   for(int i=0;i<matrix.size();i++)
       // {
       //     if(binary_search(matrix[i].begin(),matrix[i].end(),target)) //for each row seeing wether that value exists or not
       //  return true; 
       //  }
       //  return false;
};