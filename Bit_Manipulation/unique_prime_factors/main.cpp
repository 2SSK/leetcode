// =============================================
//  You will input in the input.txt file      ||
//  Output will be printed in output.txt file ||
// ============================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  vector<int> AllPrimeFacts(int n) {
    if (n <= 1)
      return {};

    vector<int> primeFacts;

    for (int i{2}; i * i <= n; i++) {
      if (n % i == 0) {
        primeFacts.push_back(i);
        while (n % i == 0) {
          n /= i;
        }
      }
    }

    if (n > 1) {
      primeFacts.push_back(n);
    }

    return primeFacts;
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

  int num;
  cin >> num;

  vector<int> res = s.AllPrimeFacts(num);
  cout << "Result : ";
  s.printArr(res);

  return 0;
}
