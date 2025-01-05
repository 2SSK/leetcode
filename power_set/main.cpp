// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  vector<vector<int>> powerSet(vector<int> &nums) {
    vector<vector<int>> res;
    int n = nums.size();
    int totalSubsets{1 << n};

    for (int i{}; i < totalSubsets; ++i) {
      vector<int> subset;
      for (int j{}; j < n; ++j) {
        if (i & (1 << j)) {
          subset.push_back(nums[j]);
        }
      }
      res.push_back(subset);
    }

    return res;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;
  int size{};
  cin >> size;

  vector<int> arr(size);
  for (int i{}; i < size; i++) {
    cin >> arr[i];
  }

  vector<vector<int>> result;
  result = s.powerSet(arr);

  for (const auto &subset : result) {
    cout << "{ ";
    for (int x : subset) {
      cout << x << " ";
    }
    cout << "}\n";
  }

  return 0;
}
