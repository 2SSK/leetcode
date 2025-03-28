// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution s;

  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i{}; i < size; i++) {
    cin >> arr[i];
  }

  int k;
  cin >> k;

  cout << "Output: " << s.maxScore(arr, k) << endl;

  return 0;
}

int Solution::maxScore(vector<int> &cardPoints, int k) {
  int n = cardPoints.size();
  int lSum = 0, rSum = 0, maxSum = 0;

  for (int i = 0; i < k; i++)
    lSum += cardPoints[i];

  maxSum = lSum;

  int rIndex = n - 1;
  for (int i = k - 1; i >= 0; i--) {
    lSum -= cardPoints[i];
    rSum += cardPoints[rIndex];
    rIndex--;

    maxSum = max(maxSum, lSum + rSum);
  }

  return maxSum;
};
