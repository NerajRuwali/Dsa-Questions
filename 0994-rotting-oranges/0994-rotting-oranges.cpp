class Solution {
public:
int row[4]={-1,0,0,1};
int col[4]={0,1,-1,0};
int r;
int c;
bool valid(int i,int j){
    return i>=0&&i<r&&j>=0&&j<c;
}
    int orangesRotting(vector<vector<int>>& grid) {
    
        queue<pair<int,int>>q;
        r=grid.size();
        c=grid[0].size();
      int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            int size=q.size();
            count++;
            for(int i=0;i<size;i++){
            int new_i=q.front().first;
            int new_j=q.front().second;
            
            q.pop();
            for(int k=0;k<4;k++){
                 if(valid(new_i+row[k],new_j+col[k])&&grid[new_i+row[k]][new_j+col[k]]==1){
                    q.push({new_i+row[k],new_j+col[k]});
                    grid[new_i+row[k]][new_j+col[k]]=2;
                 }
            }
        }
        }

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(count-1<0){
            return 0;
        }
        return count-1;

    }
};