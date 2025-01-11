// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

void printArr(vector<int> arr);

class solution {
public:
  // Brute force approach
  vector<int> divisors(int n) {
    vector<int> allDivisors;

    for (size_t i{1}; i <= n; i++) {
      if (n % i == 0)
        allDivisors.push_back(i);
    }

    return allDivisors;
  }

  // Optimized approach
  vector<int> divisorOptimized(int n) {
    vector<int> allDivisors;

    for (int i{1}; i <= sqrt(n); i++) {
      if (n % i == 0) {
        allDivisors.push_back(i);
        if (n % i != i) {
          allDivisors.push_back(n / i);
        }
      }
    }

    // Sort the Array
    sort(begin(allDivisors), end(allDivisors));

    return allDivisors;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  int n;
  cin >> n;

  vector<int> allDivisors = s.divisorOptimized(n);
  /*printArr(allDivisors);*/
  printArr(allDivisors);

  return 0;
}

void printArr(vector<int> arr) {
  int n = arr.size();

  cout << "| ";
  for (size_t i{}; i < n; i++) {
    if (i == n - 1)
      cout << arr[i] << " |";
    else
      cout << arr[i] << " | ";
  }
}
