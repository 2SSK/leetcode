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

  template <typename T> void printMatrix(vector<vector<T>> arr) {
    cout << "\n";
    for (const auto &row : arr) {
      printArr(row);
    }
  }
};

class Solution : public Utils {
public:
  int snakesAndLadders(vector<vector<int>> &board);
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

  cout << "Output: " << solution.snakesAndLadders(inputArr) << "\n";

  return 0;
}

int Solution::snakesAndLadders(vector<vector<int>> &board) {
  int n = board.size();
  int MAX = n * n;
  queue<int> q;
  q.push(1);
  vector<bool> visited(MAX + 1, false);
  visited[1] = true;

  int level = 0;
  while (!q.empty()) {
    int size = q.size();
    for (int i = 0; i < size; i++) {
      int curr = q.front();
      q.pop();

      if (curr == MAX)
        return level;

      for (int next = curr + 1; next <= min(curr + 6, MAX); ++next) {
        int dest = next;

        int row = (next - 1) / n;
        int col = (next - 1) % n;
        if (row % 2 == 1)
          col = n - 1 - col;
        row = n - 1 - row;

        if (board[row][col] != -1)
          dest = board[row][col];

        if (!visited[dest]) {
          visited[dest] = true;
          q.push(dest);
        }
      }
    }
    level++;
  }

  return -1;
};
