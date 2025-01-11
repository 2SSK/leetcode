// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  // Brute force approach

  // Helper function to verify prime number
  bool isPrime(int n) {
    if (n <= 1)
      return false;
    if (n <= 3)
      return true;

    if (n % 2 == 0 || n % 3 == 0)
      return false;

    for (size_t i{5}; i * i <= n; i += 6) {
      if (n % i == 0 || n % (i + 2) == 0)
        return false;
    }

    return true;
  }

  // Main function to count all primes till n
  vector<int> countPrimes(int n) {
    vector<int> primes;

    for (size_t i{1}; i < n; i++) {
      if (isPrime(i))
        primes.push_back(i);
    }

    return primes;
  }

  // Optimal approach
  vector<int> countPrimeSieve(int n) {
    vector<int> primes;
    vector<bool> isPrime(n + 1, true);

    // Mark 0 and 1 as non-prime
    isPrime[0] = isPrime[1] = false;

    for (size_t i{2}; i * i <= n; i++) {
      if (isPrime[i]) {
        // Mark multiples of i as non-prime
        for (size_t j{i * i}; j <= n; j += i) {
          isPrime[j] = false;
        }
      }
    }

    for (size_t i{}; i < isPrime.size(); i++) {
      if (isPrime[i])
        primes.push_back(i);
    }

    return primes;
  }
};

void printArr(vector<int> arr);

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  int n;
  cin >> n;

  vector<int> primes = s.countPrimeSieve(n);
  printf("Total Primes (less than %d) : %d\n", n, primes.size());
  printArr(primes);

  return 0;
}

void printArr(vector<int> arr) {
  int n = arr.size();

  cout << "| ";
  for (int i{}; i < n; i++) {
    if (i == n - 1) {
      cout << arr[i] << "|\n";
    } else {
      cout << arr[i] << " | ";
    }
  }
}
