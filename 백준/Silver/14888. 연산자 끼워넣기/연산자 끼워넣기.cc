#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> vc;
vector<int> op;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  for (int i = 0; i < 4; i++) {
    cin >> t;
    for (int k = 0; k < t; k++) {
      op.push_back(i);
    }
  }
  int max_ans = INT_MIN;
  int min_ans = INT_MAX;
  do {
    int rst = 0;
    switch (op[0]) {
    case 0:
      rst = vc[0] + vc[1];
      break;
    case 1:
      rst = vc[0] - vc[1];
      break;
    case 2:
      rst = vc[0] * vc[1];
      break;
    case 3:
      rst = vc[0] / vc[1];
      break;
    }
    for (int i = 1; i < n - 1; i++) {
      switch (op[i]) {
      case 0:
        rst = rst + vc[i + 1];
        break;
      case 1:
        rst = rst - vc[i + 1];
        break;
      case 2:
        rst = rst * vc[i + 1];
        break;
      case 3:
        rst = rst / vc[i + 1];
        break;
      }
    }
    max_ans = max(max_ans, rst);
    min_ans = min(min_ans, rst);
  } while (next_permutation(op.begin(), op.end()));
  cout << max_ans << "\n" << min_ans;
  return 0;
}