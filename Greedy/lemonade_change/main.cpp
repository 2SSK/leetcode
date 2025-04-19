// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Solution {
public:
  bool lemonadeChange(vector<int> &bills);

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

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  vector<int> input = solution.readInput<int>();

  cout << "Output: " << boolalpha << solution.lemonadeChange(input) << endl;

  return 0;
}

bool Solution::lemonadeChange(vector<int> &bills) {
  int five_count = 0;
  int ten_count = 0;

  for (int i = 0; i < bills.size(); i++) {
    if (bills[i] == 5) {
      five_count++;
    } else if (bills[i] == 10) {
      if (five_count) {
        five_count--;
        ten_count++;
      } else {
        return false;
      }
    } else {
      if (ten_count && five_count) {
        ten_count--;
        five_count--;
      } else if (five_count >= 3) {
        five_count -= 3;
      } else {
        return false;
      }
    }
  }

  return true;
};
