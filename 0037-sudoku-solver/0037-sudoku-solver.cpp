class Solution {
    bool solved = false;
    void rec(int i, int j, vector<vector<char>>& board) {
        if(i == 9) {
            solved = true;
            return;
        }

        int nxtI = i + ((j+1)/9);
        int nxtJ = (j + 1)%9;
        // cout<<i<<"-"<<j<<" ";

        if(board[i][j] == '.') {
            for(char x='1';x<='9';x++) {
                if(isAllowed(i, j, board, x)) {
                    board[i][j] = x;
                    rec(nxtI, nxtJ, board);
                    if(solved) return;
                    board[i][j] = '.';
                }
            }
        }
        else rec(nxtI, nxtJ, board);
    }

    bool isAllowed(int i, int j, vector<vector<char>>& board, char ch) {
        int rStart = (i/3)*3;
        int cStart = (j/3)*3;

        for(int x=0;x<9;x++) if(board[i][x] == ch || board[x][j] == ch) return false;

        for(int x=rStart;x<rStart+3;x++)
            for(int y=cStart;y<cStart+3;y++) if(board[x][y] == ch) return false;

        return true; 
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rec(0, 0, board);
    }
};