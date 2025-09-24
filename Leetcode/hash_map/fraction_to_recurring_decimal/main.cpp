#include <bits/stdc++.h>
#include <cstdlib>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
  string fractionToDecimal(int numerator, int denominator);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int numerator, denominator;
  cin >> numerator >> denominator;

  cout << "Output: " << solution.fractionToDecimal(numerator, denominator);

  return 0;
}

string Solution::fractionToDecimal(int numerator, int denominator) {
  if (numerator == 0)
    return to_string(0);

  string output;

  if ((numerator < 0) ^ (denominator < 0)) {
    output.append("-");
  }

  long long num = llabs((long long)numerator);
  long long den = llabs((long long)denominator);

  output += to_string(num / den);
  long long remainder = num % den;

  if (remainder == 0)
    return output;

  output += ".";

  unordered_map<long long, int> remainderIndex;

  while (remainder != 0) {
    if (remainderIndex.find(remainder) != remainderIndex.end()) {
      output.insert(remainderIndex[remainder], "(");
      output += ")";
      break;
    }

    remainderIndex[remainder] = output.size();

    remainder *= 10;
    output += to_string(remainder / den);
    remainder %= den;
  }

  return output;
}
