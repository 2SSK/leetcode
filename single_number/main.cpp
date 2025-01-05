// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  int singleNumber(vector<int> &nums) {
    int num{};
    /*cout << "num(ini) : " << num << "\n";*/

    for (auto it : nums) {
      num = num ^ it;
      /*cout << "num(it): " << num << "\n";*/
    }

    return num;
  }
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  solution s;

  int size;
  cin >> size;

  vector<int> arr(size);
  for (int i{}; i < size; i++) {
    cin >> arr[i];
  }

  int result = s.singleNumber(arr);
  cout << result << "\n";

  return 0;
}
