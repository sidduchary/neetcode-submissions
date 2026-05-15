class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int,int> sq;
        vector<vector<int>> idxs = {{0,0}, {0,3}, {0,6},
                                    {3,0}, {3,3}, {3,6},
                                    {6,0}, {6,3}, {6,6}};

        for(auto& it: idxs) {
            int x=it[0], y=it[1];
            sq.clear();
            for(int m=0; m<3; m++) {
                for(int n=0; n<3; n++) {
                    sq[int(board[m+x][n+y])]++;
                }
            }

            for(int i=0; i<3; i++) {
                for(int j=0; j<3; j++) {
                    if(board[i+x][j+y] == '.') continue;

                    for(int k=0; k<9; k++) {
                        if(k!=j+y && board[i+x][k] == board[i+x][j+y]) return 0;
                    }
                    
                    for(int k=0; k<9; k++) {
                        if(k!=i+x && board[k][j+y] == board[i+x][j+y]) return 0;
                    }

                    int t = int(board[i+x][j+y]);
                    if(sq.find(t) != sq.end() && sq[t]>1) return 0;
                }
            }
        }
        return 1;
    }
};
