class Solution {
public:
    bool check(vector<string> &board, int row, int col) {
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }
        for (int i = row, j = col; i >= 0 && j < board.size(); i--, j++) {
            if (board[i][j] == 'Q') {
                return false;
            }
        }

        return true;
    }

    void queens(int row, vector<string> &board, vector<bool> &cols, vector<vector<string>> &ans) {
        if (row == board.size()) {
            ans.push_back(board);
            return;
        }

        for (int i = 0; i < board.size(); i++) {
            if (cols[i]) {
                continue;
            }

            if (check(board, row, i)) {
                board[row][i] = 'Q';
                cols[i] = true;

                queens(row + 1, board, cols, ans);

                board[row][i] = '.';
                cols[i] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);

        vector<vector<string>> ans;

        queens(0, board, cols, ans);

        return ans;
    }
};