class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> row(9), col(9), mat(9);

        for(int i=0; i<9; i++) {
            for (int j=0; j<9; j++) {
                if(board[i][j] == '.') continue;

                if(row[i].count(board[i][j])) return 0;
                row[i].insert(board[i][j]);

                if(col[j].count(board[i][j])) return 0;
                col[j].insert(board[i][j]);
                
                if(mat[(i/3)*3 + (j/3)].count(board[i][j])) return 0;
                mat[(i/3)*3 + (j/3)].insert(board[i][j]);
            }
        }
        return 1;
    }
};
