// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  string IntToRoman(int num);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int input_integer;
  cin >> input_integer;

  cout << "Output: " << solution.IntToRoman(input_integer) << endl;

  return 0;
}

string Solution::IntToRoman(int num) {
  vector<pair<int, string>> valueMap = {
      {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
      {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
      {5, "V"},    {4, "IV"},   {1, "I"}};

  string roman_value = "";

  for (auto &[val, symbol] : valueMap) {
    while (num >= val) {
      roman_value += symbol;
      num -= val;
    }
  }

  return roman_value;
};
