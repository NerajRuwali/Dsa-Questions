class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        set<string> seen; // this set stores the unique value

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                if(board[i][j]=='.') continue; // skip empty spaces in the suduko

                string num(1,board[i][j]);

                if(!seen.insert(num + "row" + to_string(i)).second ||
                   !seen.insert(num + "col" + to_string(j)).second ||
                   !seen.insert(num + "box" + to_string(i/3) + to_string(j/3)).second)
                {
                    return false;
                }
            }
        }

        return true;
    }
};