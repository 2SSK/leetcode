// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <cmath>
#include <cstddef>
using namespace std;

class solution {
public:
  vector<int> sieveOfErtothenes(int n) {
    vector<bool> isPrime(n + 1, true);

    isPrime[0] = isPrime[1] = false;

    for (size_t i{2}; i <= sqrt(n); i++) {
      if (isPrime[i]) {
        for (size_t multiple{i * i}; multiple <= n; multiple += i) {
          isPrime[multiple] = false;
        }
      }
    }

    vector<int> primes;
    for (size_t i{2}; i <= n; i++) {
      if (isPrime[i]) {
        primes.push_back(i);
      }
    }

    return primes;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  int n;
  cin >> n;

  vector<int> primeFactors = s.sieveOfErtothenes(n);

  for (size_t i{}; i < primeFactors.size(); i++) {
    cout << primeFactors[i] << "\n";
  }

  return 0;
}
