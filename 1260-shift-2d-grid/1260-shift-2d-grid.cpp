class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int total = m * n;

        k %= total;

        vector<vector<int>> ans(m , vector<int>(n));
        for(int i = 0; i< m ;i++){
            for(int j= 0 ; j< n ; j++){
                int oldIndex = i * n + j;
                int newIndex = (oldIndex + k)% total;

                int x = newIndex/n;
                int y = newIndex%n;

                ans[x][y] = grid[i][j];
            }
        }
        return ans;
    }
};