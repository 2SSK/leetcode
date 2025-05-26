// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  template <typename T> vector<T> readInput() {
    vector<T> inputArr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    T value;
    while (ss >> value) {
      inputArr.push_back(value);
    }

    return inputArr;
  }

  template <typename T> void printArr(vector<T> arr) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        cout << "[ " << arr[i] << " | ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  void printMatrix(vector<vector<char>> &matrix) {
    cout << "[\n";
    for (const auto &row : matrix) {
      printArr(row);
    }
    cout << "]";
  }

  bool isValidSudoku(vector<vector<char>> &board);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n = 9;

  vector<vector<char>> matrix;

  while (n--) {
    vector<char> input = solution.readInput<char>();

    matrix.push_back(input);
  }

  cout << "Output: " << boolalpha << solution.isValidSudoku(matrix) << "\n";

  return 0;
}

bool Solution::isValidSudoku(vector<vector<char>> &board) {
  // Validate rows
  for (int i = 0; i < 9; ++i) {
    unordered_set<char> seen;
    for (int j = 0; j < 9; ++j) {
      if (board[i][j] != '.') {
        if (seen.count(board[i][j])) {
          return false;
        }
        seen.insert(board[i][j]);
      }
    }
  }

  // Validate columns
  for (int j = 0; j < 9; ++j) {
    unordered_set<char> seen;
    for (int i = 0; i < 9; ++i) {
      if (board[i][j] != '.') {
        if (seen.count(board[i][j])) {
          return false;
        }
        seen.insert(board[i][j]);
      }
    }
  }

  // Validate 3x3 sub-boxes
  for (int boxRow = 0; boxRow < 3; ++boxRow) {
    for (int boxCol = 0; boxCol < 3; ++boxCol) {
      unordered_set<char> seen;
      for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
          char current = board[boxRow * 3 + i][boxCol * 3 + j];
          if (current != '.') {
            if (seen.count(current)) {
              return false;
            }
            seen.insert(current);
          }
        }
      }
    }
  }

  return true;
}
