// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class solution {
public:
  // Bruteforce O(n^2) solution
  int countSubarraysWithSumK(vector<int> &arr, int k) {
    int count{};
    int size = arr.size();

    for (int i{}; i < size; i++) {
      int currentSum{};
      for (int j{i}; j < size; j++) {
        currentSum += arr[j];
        if (currentSum == k) {
          count++;
        }
      }
      currentSum = 0;
    }

    return count;
  }

  // Optimal O(n) solution
  int countSubarrays(vector<int> &arr, int k) {
    unordered_map<int, int> prefixSumFreq;
    int count{};
    int prefixSum{};

    // Base case: There is one way to have a prefix sum of 0.
    prefixSumFreq[0] = 1;

    for (int num : arr) {
      prefixSum += num;

      // Check if there is a subarrya ending here with sum k;
      if (prefixSumFreq.find(prefixSum - k) != prefixSumFreq.end()) {
        count += prefixSumFreq[prefixSum - k];
      }

      // Update the frequency of the current prefix sum.
      prefixSumFreq[prefixSum]++;
    }

    return count;
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  int size, k;
  cin >> size >> k;

  vector<int> arr(size);
  for (int i{}; i < size; i++) {
    cin >> arr[i];
  }

  int result = s.countSubarrays(arr, k);

  cout << result << "\n";

  return 0;
}
