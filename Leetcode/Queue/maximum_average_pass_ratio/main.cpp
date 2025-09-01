#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
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

  template <typename T> void printArr(vector<T> arr) {
    cout << "[";
    for (int i = 0; i < arr.size(); i++) {
      cout << arr[i];
      if (i != arr.size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
  }

  template <typename T> void printMatrix(vector<vector<T>> matrix) {
    cout << "[";
    for (int i = 0; i < matrix.size(); i++) {
      printArr(matrix[i]);
      if (i != matrix.size() - 1) {
        cout << ", ";
      }
    }
    cout << "]";
  }

  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents);
};

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Solution solution;

  int n;
  cin >> n;
  cin.ignore(); // Ignore the newline character after the integer input

  vector<vector<int>> classes(n);
  for (int i = 0; i < n; i++) {
    classes[i] = solution.readInput<int>();
  }

  int extraStudents;
  cin >> extraStudents;

  cout << "Output: " << solution.maxAverageRatio(classes, extraStudents)
       << endl;

  return 0;
}

double Solution::maxAverageRatio(vector<vector<int>> &classes,
                                 int extraStudents) {
  // Lambda to calculate the gain of adding an extra student
  auto calculateGain = [](int passes, int totalStudents) {
    return (double)(passes + 1) / (totalStudents + 1) -
           (double)passes / totalStudents;
  };

  // Max heap to store (-gain, passes, totalStudents)
  priority_queue<pair<double, pair<int, int>>> maxHeap;
  for (const auto &singleClass : classes) {
    maxHeap.push({calculateGain(singleClass[0], singleClass[1]),
                  {singleClass[0], singleClass[1]}});
  }

  // Distribute extra students
  while (extraStudents--) {
    auto [currentGain, classInfo] = maxHeap.top();
    maxHeap.pop();
    int passes = classInfo.first;
    int totalStudents = classInfo.second;
    maxHeap.push({calculateGain(passes + 1, totalStudents + 1),
                  {passes + 1, totalStudents + 1}});
  }

  // Calculate the final average pass ratio
  double totalPassRatio = 0;
  while (!maxHeap.empty()) {
    auto [_, classInfo] = maxHeap.top();
    maxHeap.pop();
    totalPassRatio += (double)classInfo.first / classInfo.second;
  }

  return totalPassRatio / classes.size();
}
