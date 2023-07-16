#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
vector<string> vc;
bool ok[28];
int ans = 0;

bool cmp(string &s1, string &s2) {
  if (s1.size() > s2.size()) {
    return true;
  } else {
    if (s1.size() == s2.size()) {
      if (s1 > s2) {
        return true;
      }
    }
  }
  return false;
}

void solve(int cnt, int idx) {
  if (cnt >= k) {
    if (cnt == k) {
      int t = 0;
      for (string str : vc) {
        bool flag = true;
        for (auto c : str) {
          if (ok[c - 'a']) {
            continue;
          } else {
            flag = false;
            break;
          }
        }
        if (flag)
          t++;
      }
      if (t > ans)
        ans = t;
    }
    return;
  }
  for (int i = idx; i < 26; i++) {
    if (ok[i])
      continue;
    ok[i] = true;
    solve(cnt + 1, i + 1);
    ok[i] = false;
  }
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // a n t i c
  cin >> n >> k;
  string tmp;
  for (int i = 0; i < n; i++) {
    cin >> tmp;
    vc.push_back(tmp);
  }
  if (k <= 4) {
    cout << 0;
    return 0;
  }
  unordered_map<char, int> M;
  ok['a' - 'a'] = 1;
  ok['n' - 'a'] = 1;
  ok['t' - 'a'] = 1;
  ok['i' - 'a'] = 1;
  ok['c' - 'a'] = 1;
  k -= 5;
  solve(0, 0);
  cout << ans;
  return 0;
}