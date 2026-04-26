class Solution {
public:
    int n, m;
    vector<vector<int>> visited;
    
    bool dfs(vector<vector<char>>& grid, int i, int j, int pi, int pj) {
        visited[i][j] = 1;
        
        int dirs[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};
        
        for(auto &d : dirs) {
            int ni = i + d[0];
            int nj = j + d[1];
            
            if(ni < 0 || nj < 0 || ni >= n || nj >= m)
                continue;
            
            if(grid[ni][nj] != grid[i][j])
                continue;
            
            if(!visited[ni][nj]) {
                if(dfs(grid, ni, nj, i, j))
                    return true;
            }
            else if(ni != pi || nj != pj) {
                return true; 
            }
        }
        return false;
    }
    
    bool containsCycle(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        
        visited.assign(n, vector<int>(m, 0));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j]) {
                    if(dfs(grid, i, j, -1, -1))
                        return true;
                }
            }
        }
        return false;
    }
};