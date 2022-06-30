// isPossible function
int isPossible(int mid, vector<int>&A, int B)
{
    int studentCount=0;
    int pageAllocated=0;
    int n=A.size();
    for(int i=0;i<n;i++)
    {
        if(pageAllocated+A[i]>mid)
        {
            studentCount++;
            pageAllocated=A[i];
                  if (pageAllocated > mid) return false;

        }else{
            pageAllocated+=A[i];
        }
    }
    if(studentCount<B) return true;
    else return false;
}
int Solution::books(vector<int> &A, int B) {
    int n=A.size();
    int low=0,high=0;
    for(int i=0;i<n;i++)
    {
        high+=A[i];
        low=min(low,A[i]);
    }
    while(low<=high)
    {
        int mid=(low+high)/2;
        // check if for that mid is boolk allocation possible? if yes than it should be for even lesss high value hence decreasing it
        if(isPossible(mid, A,B))
        {
            high=mid-1;
        }
        else low=mid+1;
    }
    return low;
}


