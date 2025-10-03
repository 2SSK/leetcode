#include <bits/stdc++.h>
#include <queue>
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
  int trapRainWater(vector<vector<int>> &heightMap);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;

  vector<vector<int>> heightMap(n);

  while (n--) {
    vector<int> input = solution.readInput<int>();
    heightMap.push_back(input);
  }

  cout << "Output: " << solution.trapRainWater(heightMap);

  return 0;
}

int Solution::trapRainWater(vector<vector<int>> &heightMap) {
  if (heightMap.empty() || heightMap[0].empty())
    return 0;

  int rows = heightMap.size();
  int cols = heightMap[0].size();

  vector<vector<int>> visited(rows, vector<int>(cols, 0));

  using Cell = tuple<int, int, int>;
  priority_queue<Cell, vector<Cell>, greater<Cell>> minHeap;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
        minHeap.push({heightMap[i][j], i, j});
        visited[i][j] = 1;
      }
    }
  }

  int trappedWater = 0;
  vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  while (!minHeap.empty()) {
    auto [h, x, y] = minHeap.top();
    minHeap.pop();

    for (auto [dx, dy] : dirs) {
      int nx = x + dx;
      int ny = y + dy;

      if (nx >= 0 && nx < rows && ny >= 0 && ny < cols && !visited[nx][ny]) {
        visited[nx][ny] = 1;

        if (heightMap[nx][ny] < h) {
          trappedWater += h - heightMap[nx][ny];
        }

        minHeap.push({max(h, heightMap[nx][ny]), nx, ny});
      }
    }
  }

  return trappedWater;
}
