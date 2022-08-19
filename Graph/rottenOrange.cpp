class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        // direction co-ordinates
        
        vector<int> dx = {-1, 0, 1, 0};
        
        vector<int> dy = {0, 1, 0, -1};
        
        int minutes = 0;
        
        // push the cordinates of rotten orange into queue
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 2)
                {
                    q.push({i, j});
                }
            }
        }
        
        // apply bfs
        
        while(!q.empty())
        {
            int size = q.size();
            
            // iterate for one complete level
           
            for(int k = 0; k < size; k++)
            {
                auto curr = q.front();
                
                q.pop();
                
                // index of curr cell
                
                int i = curr.first;
                
                int j = curr.second;
                
                // try out all 4 directions
                
                for(int d = 0; d < 4; d++)
                {
                    // find the index of new cell
                    
                    int new_i = i + dx[d];
                    
                    int new_j = j + dy[d];
                    
                    if(new_i >= 0 && new_i < n && new_j >= 0 && new_j < m && grid[new_i][new_j] == 1)
                    {
                        // push the index of new cell into queue
                        
                        q.push({new_i, new_j});
                        
                        // mark the cell rotten
                        
                        grid[new_i][new_j] = 2;
                    }
                }
            }
            
            // increment minutes
            
            minutes++;
        }
        
        // if there is any orange which is not rotten, then return -1
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                    return -1;
            }
        }
        
        // if all the oranges are rotten
        
        if(minutes == 0)
            return 0;
        
        return minutes - 1;
    }
};