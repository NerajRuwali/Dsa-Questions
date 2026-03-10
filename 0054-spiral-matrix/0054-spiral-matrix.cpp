class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector<int> ans;

        int srow = 0; // starting row
        int scol = 0; // starting coloumn
        int erow = matrix.size() - 1; // endig row
        int ecol = matrix[0].size() - 1; // ending column

        while(srow <= erow && scol <= ecol){

            // left to right
            for(int j = scol; j <= ecol; j++){
                ans.push_back(matrix[srow][j]);
            }
            srow++;

            // top to bottom
            for(int i = srow; i <= erow; i++){
                ans.push_back(matrix[i][ecol]);
            }
            ecol--;

            // right to left
            if(srow <= erow){
                for(int j = ecol; j >= scol; j--){
                    ans.push_back(matrix[erow][j]);
                }
                erow--;
            }

            // bottom to top
            if(scol <= ecol){
                for(int i = erow; i >= srow; i--){
                    ans.push_back(matrix[i][scol]);
                }
                scol++;
            }
        }

        return ans;
    }
};