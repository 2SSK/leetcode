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
};

int kthSmallest(vector<int> &arr, int k) {
  priority_queue<int> pq;

  for (int i = 0; i < arr.size(); i++) {
    pq.push(arr[i]);

    if (pq.size() > k) {
      pq.pop();
    }
  }

  return pq.top();
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int testCases;
  cin >> testCases;
  cin.ignore();

  while (testCases--) {
    vector<int> input = solution.readInput<int>();
    int k;
    cin >> k;
    cin.ignore();

    cout << "Output: " << kthSmallest(input, k) << endl;
  }

  return 0;
}
