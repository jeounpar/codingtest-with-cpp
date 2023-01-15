#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, c;
int arr[1001];
map<int, int> M, M_first;

bool cmp(vector<int> &a, vector<int> &b) {
  if (a[2] > b[2])
    return true;
  else if (a[2] == b[2]) {
    if (a[1] < b[1])
      return true;
  }
  return false;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> c;
  int t;
  int idx = 1;
  for (int i = 0; i < n; i++) {
    cin >> t;
    M[t] += 1;
    if (M_first[t] == 0) {
      M_first[t] = idx;
      idx++;
    }
  }

  vector<vector<int>> vc;
  for (auto a : M) {
    vector<int> tmp;
    tmp.push_back(a.first);
    tmp.push_back(M_first[a.first]);
    tmp.push_back(a.second);
    vc.push_back(tmp);
  }
  sort(vc.begin(), vc.end(), cmp);
  for (auto a : vc) {
    for (int i = 0; i < a[2]; i++)
      cout << a[0] << " ";
  }
  return 0;
}