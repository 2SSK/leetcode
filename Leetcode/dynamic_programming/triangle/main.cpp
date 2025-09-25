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

  int minimumTotal(vector<vector<int>> &triangle);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;
  cin.ignore();

  vector<vector<int>> triangle(n);

  for (int i = 0; i < n; i++) {
    triangle[i] = solution.readInput<int>();
  }

  cout << "Output: " << solution.minimumTotal(triangle);

  return 0;
}

int Solution::minimumTotal(vector<vector<int>> &triangle) {
  int n = triangle.size();

  for (int row = n - 2; row >= 0; row--) {

    for (int col = 0; col < triangle[row].size(); col++) {
      triangle[row][col] +=
          min(triangle[row + 1][col], triangle[row + 1][col + 1]);
    }
  }

  return triangle[0][0];
}
