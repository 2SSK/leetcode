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
        cout << "[ " << arr[i] << ", ";
      } else if (i == n - 1) {
        cout << arr[i] << " ]\n";
      } else {
        cout << arr[i] << ", ";
      }
    }
  }

  int recurBinarySearch(vector<int> &arr, int low, int high, int target) {
    if (low > high)
      return -1;

    int mid = low + (high - low) / 2;

    if (arr[mid] == target) {
      return mid;
    } else if (arr[mid] < target) {
      return recurBinarySearch(arr, mid + 1, high, target);
    } else {
      return recurBinarySearch(arr, low, mid - 1, target);
    }

    return -1;
  }

  int binarysearch(vector<int> &arr, int k) {
    return recurBinarySearch(arr, 0, arr.size() - 1, k);
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int test_cases;
  cin >> test_cases;
  cin.ignore();

  while (test_cases--) {
    vector<int> arr = solution.readInput<int>();
    int target;
    cin >> target;
    cin.ignore();

    cout << "Output: " << solution.binarysearch(arr, target) << endl;
  }

  return 0;
}
