class Solution {
public:
    bool isValid(int row, int col,int n, int m,vector<vector<char>>& grid)
    {
        if(row>=0 && row<n && col>=0 && col<m && grid[row][col]=='1')
            return true;
        return false;
    }
    void dfs(int row, int col,int n, int m,vector<vector<char>>& grid)
    {
        grid[row][col]='0';
        if(isValid(row+1,col,n,m,grid))
            dfs(row+1,col,n,m,grid);
         if(isValid(row-1,col,n,m,grid))
            dfs(row-1,col,n,m,grid);
         if(isValid(row,col+1,n,m,grid))
            dfs(row,col+1,n,m,grid);
         if(isValid(row,col-1,n,m,grid))
            dfs(row,col-1,n,m,grid);
        
    }
        int numIslands(vector<vector<char>>& grid) {
        int count=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    count++;
                    dfs(i,j,n,m,grid);
                }
            }
        }
        return count;
    }
};