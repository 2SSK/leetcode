// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  vector<int> sumClosest(vector<int> &arr, int target) {
    vector<int> ans;
    int n = arr.size();
    int l{}, r{n - 1};
    int minDiff{INT_MAX};

    sort(begin(arr), end(arr));

    while (l < r) {
      int sum = arr[l] + arr[r];
      int diff = abs(target - sum);

      if (diff < minDiff) {
        ans.clear();
        ans = {arr[l], arr[r]};
        minDiff = diff;
      }

      if (sum == target)
        break;
      else if (sum < target)
        l++;
      else
        r--;
    }

    return ans;
  }

  void printArr(vector<int> arr) {
    int n = arr.size();

    cout << "| ";
    for (int i{}; i < n; i++) {
      (i == n - 1) ? cout << arr[i] << " |" : cout << arr[i] << " | ";
    }
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  int size, target;
  cin >> size >> target;

  vector<int> arr(size);
  for (size_t i{}; i < size; i++) {
    cin >> arr[i];
  }

  vector<int> pairs = s.sumClosest(arr, target);

  s.printArr(pairs);

  return 0;
}
