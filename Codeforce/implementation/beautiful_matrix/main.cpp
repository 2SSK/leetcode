#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<vector<int>> matrix(5, vector<int>(5));

  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      cin >> matrix[i][j];
    }
  }

  int row_of_one = -1, col_of_one = -1;

  for (int i = 0; i < 5; ++i) {
    auto it = find(matrix[i].begin(), matrix[i].end(), 1);
    if (it != matrix[i].end()) {
      row_of_one = i + 1;
      col_of_one = (it - matrix[i].begin()) + 1;
      break;
    }
  }

  int move = abs(3 - row_of_one) + abs(3 - col_of_one);

  cout << move << "\n";

  return 0;
}
