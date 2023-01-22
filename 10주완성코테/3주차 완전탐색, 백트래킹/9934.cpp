#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int k;
int tree[1200];
vector<int> ret[14];

void solve(int s, int e, int level) {
  if (s > e)
    return;
  if (s == e) {
    ret[level].push_back(tree[s]);
    return;
  }
  int mid = (s + e) / 2;
  ret[level].push_back(tree[mid]);
  solve(s, mid - 1, level + 1);
  solve(mid + 1, e, level + 1);
  return;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> k;
  int ed = (int)pow(2, k) - 1;
  for (int i = 0; i < ed; i++)
    cin >> tree[i];
  solve(0, ed, 1);
  for (int i = 1; i <= k; i++) {
    for (int j : ret[i]) {
      cout << j << " ";
    }
    cout << "\n";
  }
  return 0;
}