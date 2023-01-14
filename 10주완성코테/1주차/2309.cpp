#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  vector<int> arr;
  int n;
  for (int i = 0; i < 9; i++) {
    cin >> n;
    arr.push_back(n);
  }
  int st = -1, ed = -1;
  sort(arr.begin(), arr.end());
  vector<int> vc;
  for (int i = 0; i < 2; i++)
    vc.push_back(0);
  for (int i = 0; i < 7; i++)
    vc.push_back(1);
  do {
    int sum = 0;
    for (int i = 0; i < 9; i++) {
      if (vc[i])
        sum += arr[i];
    }
    if (sum == 100) {
      for (int i = 0; i < 9; i++) {
        if (vc[i])
          cout << arr[i] << "\n";
      }
      break;
    }
  } while (next_permutation(vc.begin(), vc.end()));

  return 0;
}