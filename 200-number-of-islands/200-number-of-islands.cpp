class Solution {
public:
    
    // direction coordinates of left, right, top, bottom
    
    vector<int> dx = {-1, 0, 1, 0};
    
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(vector<vector<char>>& grid, int i, int j, int n, int m)
    {
        // base case
        
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
            return;
        
        // mark curr cell as visited
        
        grid[i][j] = '0';
        
        // visit in all the four directions
        
        for(int k = 0; k < 4; k++)
        {
            int new_row = i + dx[k];
            
            int new_col = j + dy[k];
            
            dfs(grid, new_row, new_col, n, m);
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        
        int m = grid[0].size();
        
        // count will store the no. of islands
        
        int count = 0;
        
        // call dfs for each cell
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    
                    dfs(grid, i, j, n, m);
                }
            }
        }
        
        return count;
    }
};