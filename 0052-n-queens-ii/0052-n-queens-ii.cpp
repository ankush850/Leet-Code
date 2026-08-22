class Solution {
private:
  std::unordered_set<int> main_diag, second_diag, column;
  int answer = 0;
  int n = 0;

  void backtracking(int row) {
    if (row == n) {
      ++answer;
      return;
    }
    for (int i = 0; i < n; ++i) {
      int check1 = row - i, check2 = row + i;
      if (main_diag.contains(check1) || second_diag.contains(check2) ||
          column.contains(i)) {
        continue;
      }
      main_diag.insert(check1);
      second_diag.insert(check2);
      column.insert(i);

      backtracking(row + 1);

      column.erase(i);
      second_diag.erase(check2);
      main_diag.erase(check1);
    }
  }

public:
  int totalNQueens(int n) {
    this->n = n;
    backtracking(0);
    return answer;
  }
};
