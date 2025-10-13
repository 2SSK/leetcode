#include <bits/stdc++.h>
#include <ios>
using namespace std;

int sumOfIndices(string s) {
  int sum = 0;
  for (const auto &word : s) {
    sum += (word - 'a') + 1;
  }

  return sum;
}

bool scoreBalance(string s) {
  int n = s.size();

  for (int i = 0; i < n; i++) {
    string s_till_i = s.substr(0, i + 1);
    string s_from_i = s.substr(i + 1, n - 1);

    int sumTillI = sumOfIndices(s_till_i);
    int sumFromI = sumOfIndices(s_from_i);

    if (sumTillI == sumFromI) {
      return true;
    }
  }
  return false;
}

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string input;
  cin >> input;

  cout << boolalpha << scoreBalance(input) << "\n";

  return 0;
}
