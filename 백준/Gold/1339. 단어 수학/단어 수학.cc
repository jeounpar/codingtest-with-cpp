#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<string> vc;
int ans = INT_MIN;
int sc[28];
set<char> st;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vc.push_back(s);
    for (int j = 0; j < s.size(); j++) {
      st.insert(s[j]);
    }
  }
  vector<char> tmp;
  for (auto c : st) {
    tmp.push_back(c);
  }
  sort(tmp.begin(), tmp.end());
  do {
    memset(sc, 0, sizeof(sc));
    for (int i = 0; i < tmp.size(); i++) {
      if (sc[tmp[i] - 'A'] == 0)
        sc[tmp[i] - 'A'] = 9 - i;
    }
    int rst = 0;
    for (auto str : vc) {
      int sum = 0;
      for (int i = 0; i < str.size(); i++) {
        sum = sum * 10 + sc[str[i] - 'A'];
      }
      rst += sum;
    }
    if (rst > ans)
      ans = rst;
  } while (next_permutation(tmp.begin(), tmp.end()));
  cout << ans;
  return 0;
}