#include <bits/stdc++.h>
#include <queue>
using namespace std;

class Solution {
private:
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

  int kthSmallest(vector<int> &arr, int k) {
    priority_queue<int> pq;

    for (int ele : arr) {
      pq.push(ele);

      if (pq.size() > k)
        pq.pop();
    }

    return pq.top();
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
    int k;
    cin >> k;
    cin.ignore();

    cout << "Output: " << solution.kthSmallest(arr, k) << endl;
  }

  return 0;
}
