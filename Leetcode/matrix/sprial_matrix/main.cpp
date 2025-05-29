// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Utils {
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

  template <typename T> void printArr(vector<vector<T>> arr) {
    cout << "\n";
    for (const auto &row : arr) {
      printArr(row);
    }
  }
};

class Solution : public Utils {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix);
  vector<int> spiralOrderWithSwitch(vector<vector<int>> &matrix);
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

  vector<int> result = solution.spiralOrder(inputArr);
  cout << "Output: ";
  solution.printArr(result);

  return 0;
}

vector<int> Solution::spiralOrder(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();
  int top = 0, bottom = n - 1;
  int left = 0, right = m - 1;
  vector<int> result;

  while (top <= bottom && left <= right) {
    // right
    for (int i = left; i <= right; i++) {
      result.push_back(matrix[top][i]);
    }
    top++;
    for (int i = top; i <= bottom; i++) {
      result.push_back(matrix[i][right]);
    }
    right--;
    if (top <= bottom) {
      for (int i = right; i >= left; i--) {
        result.push_back(matrix[bottom][i]);
      }
      bottom--;
    }
    if (left <= right) {
      for (int i = bottom; i >= top; i--) {
        result.push_back(matrix[i][left]);
      }
      left++;
    }
  }

  return result;
};

vector<int> Solution::spiralOrderWithSwitch(vector<vector<int>> &matrix) {
  int n = matrix.size();
  int m = matrix[0].size();

  int top = 0, bottom = n - 1;
  int left = 0, right = m - 1;

  int direction = 0; // 0 = right, 1 = down, 2 = left, 3 = up

  vector<int> ans;

  while (top <= bottom && left <= right) {
    switch (direction) {
    case 0:
      for (int i = left; i <= right; i++) {
        ans.push_back(matrix[top][i]);
      }
      top++;
      break;
    case 1:
      for (int i = top; i <= bottom; i++) {
        ans.push_back(matrix[i][right]);
      }
      right--;
      break;
    case 2:
      for (int i = right; i >= left; i--) {
        ans.push_back(matrix[bottom][i]);
      }
      bottom--;
      break;
    case 3:
      for (int i = bottom; i >= top; i--) {
        ans.push_back(matrix[i][left]);
      }
      left++;
      break;
    }

    direction = (direction + 1) % 4;
  }

  return ans;
}
