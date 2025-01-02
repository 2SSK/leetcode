// ==================================
//  You will input in the input.txt file
//  Output will be printed in output.txt file
// ==================================

#include <bits/stdc++.h>
using namespace std;

class solution {
public:
  int longestConsecutive(vector<int> &arr) {
    sort(arr.begin(), arr.end());
    printArr(arr);

    int count{};
    int tempCount{1};
    /*cout << "\ncount (ini) : " << count << "\n";*/
    /*cout << "temp count (ini): " << tempCount << "\n";*/

    for (int i{1}; i < arr.size(); i++) {
      if (arr[i] == arr[i - 1]) {
        /*cout << "\nele : " << arr[i] << "\nskip\n";*/
        continue;
      } else if (arr[i] == (arr[i - 1] + 1)) {
        /*cout << "\nele : " << arr[i];*/
        tempCount++;
        /*cout << "\ntemp count (if) : " << tempCount << "\n";*/
      } else {
        /*cout << "\nele : " << arr[i];*/
        count = max(count, tempCount);
        tempCount = 1;
        /*cout << "\n\ncount (else) : " << count << "\n";*/
        /*cout << "temp count (else): " << tempCount << "\n";*/
      }
    }
    count = max(count, tempCount);
    /*cout << "\ncount (fnl) : " << count << "\n";*/
    /*cout << "temp count (fnl): " << tempCount << "\n";*/

    return count;
  }

  void printArr(vector<int> arr) {
    int size = arr.size();
    for (int i{}; i < size; i++) {
      if (i == 0) {
        /*cout << "| " << arr[i];*/
      } else if (i == (size - 1)) {
        /*cout << " | " << arr[i] << " |\n";*/
      } else {
        /*cout << " | " << arr[i];*/
      }
    }
  }
};

int main() {
  solution s;

  int arrSize;
  cin >> arrSize;

  vector<int> arr(arrSize);
  int i{};
  while (i < arrSize) {
    cin >> arr[i++];
  }

  cout << s.longestConsecutive(arr);

  return 0;
}
