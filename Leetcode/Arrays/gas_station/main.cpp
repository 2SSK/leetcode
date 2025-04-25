// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void printArr(vector<int> arr, string title);
  vector<int> convert_string_to_array(string line);
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  string line1;
  getline(cin, line1);
  vector<int> gas = solution.convert_string_to_array(line1);

  string line2;
  getline(cin, line2);
  vector<int> cost = solution.convert_string_to_array(line2);

  solution.printArr(gas, "gas");
  solution.printArr(cost, "cost");

  cout << "\nOutput: " << solution.canCompleteCircuit(gas, cost);

  return 0;
}

int Solution::canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
  int total_gas = 0;
  int current_gas = 0;
  int start_index = 0;

  for (int i = 0; i < gas.size(); i++) {
    total_gas += gas[i] - cost[i];
    current_gas += gas[i] - cost[i];

    if (current_gas < 0) {
      start_index = i + 1;
      current_gas = 0;
    }
  }

  return total_gas >= 0 ? start_index : -1;
};

vector<int> Solution::convert_string_to_array(string line) {
  vector<int> array;
  stringstream ss(line);
  int value;
  while (ss >> value) {
    array.push_back(value);
  }

  return array;
}

void Solution::printArr(vector<int> arr, string title) {
  int n = arr.size();
  cout << left << setw(4) << title << ": |";
  for (int i = 0; i < n; i++) {
    cout << " " << arr[i] << " |";
  }
  cout << endl;
}
