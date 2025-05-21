// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <algorithm>
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
        cout << arr[i] << " ]";
      } else {
        cout << arr[i] << " | ";
      }
    }
  }

  template <typename T> void printArr(vector<vector<T>> arr) {
    int n = arr.size();
    cout << "\n[\n";
    for (int i = 0; i < n; i++) {
      if (i == n - 1) {
        printArr(arr[i]);
        cout << "\n]";
      } else {
        printArr(arr[i]);
        cout << "\n";
      }
    }
  }

  void setRowZeroes(vector<int> &row);
  void setColZeroes(vector<vector<int>> &matrix, int j);
  void setZeroes(vector<vector<int>> &matrix);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;
  cin.ignore();

  vector<vector<int>> inputArr;

  while (n--) {
    vector<int> input = solution.readInput<int>();
    inputArr.push_back(input);
  }

  solution.setZeroes(inputArr);

  cout << "Output: ";
  solution.printArr(inputArr);

  return 0;
}

void Solution::setRowZeroes(vector<int> &row) {
  std::fill(row.begin(), row.end(), 0);
};

void Solution::setColZeroes(vector<vector<int>> &matrix, int j) {
  for (int i = 0; i < matrix.size(); i++) {
    matrix[i][j] = 0;
  }
}

void Solution::setZeroes(vector<vector<int>> &matrix) {
  int n = matrix.size();
  if (n == 0)
    return;
  int m = matrix[0].size();

  // Step 1: Check if first row and column have zeros
  bool firstRow = false, firstCol = false;
  for (int j = 0; j < m; j++) {
    if (matrix[0][j] == 0)
      firstRow = true;
  }
  for (int i = 0; i < n; i++) {
    if (matrix[i][0] == 0)
      firstCol = true;
  }

  // Step 2: Mark rows and columns in first row/column
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (matrix[i][j] == 0) {
        matrix[i][0] = 0; // Mark row i
        matrix[0][j] = 0; // Mark column j
      }
    }
  }

  // Step 3: Zero rows based on markers in first column (skip first row)
  for (int i = 1; i < n; i++) {
    if (matrix[i][0] == 0) {
      setRowZeroes(matrix[i]);
    }
  }

  // Step 4: Zero columns based on markers in first row (skip first column)
  for (int j = 1; j < m; j++) {
    if (matrix[0][j] == 0) {
      setColZeroes(matrix, j);
    }
  }

  // Step 5: Handle first row and column
  if (firstRow)
    setRowZeroes(matrix[0]);
  if (firstCol)
    setColZeroes(matrix, 0);
}
