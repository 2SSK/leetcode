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
};

int findFloor(vector<int> &arr, int x) {
  int ans = -1;

  int low = 0;
  int high = arr.size() - 1;

  while (low <= high) {
    int mid = low + (high - low) / 2;

    if (arr[mid] <= x) {
      ans = mid;
      low = mid + 1;
    } else if (arr[mid] > x) {
      high = mid - 1;
    }
  }

  return ans;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int test_case;
  cin >> test_case;
  cin.ignore();

  while (test_case--) {
    vector<int> input = solution.readInput<int>();
    int k;
    cin >> k;
    cin.ignore();

    cout << "Output: " << findFloor(input, k) << endl;
  }

  return 0;
}
