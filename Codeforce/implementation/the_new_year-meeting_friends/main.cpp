#include <bits/stdc++.h>
using namespace std;

int main() {
  // Speed up input/output
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x1, x2, x3;
  cin >> x1 >> x2 >> x3;

  int arr[3] = {x1, x2, x3};
  sort(arr, arr + 3);

  int meeting_point = arr[1];
  int minimal_total_distance_traveled = abs(arr[0] - meeting_point) +
                                        abs(arr[1] - meeting_point) +
                                        abs(arr[2] - meeting_point);

  cout << minimal_total_distance_traveled << "\n";

  return 0;
}
