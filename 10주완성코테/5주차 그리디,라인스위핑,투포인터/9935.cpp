#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s, bomb;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> s >> bomb;
  int s_len = s.size();
  string tmp = s;
  int idx = 0;
  for (int i = 0; i < s_len; i++) {
    tmp[idx] = s[i];
    idx++;
    if (idx >= bomb.size() &&
        tmp.substr(idx - bomb.size(), bomb.size()) == bomb)
      idx -= bomb.size();
  }
  string ans = tmp.substr(0, idx);
  if (ans.size() == 0)
    cout << "FRULA";
  else
    cout << ans;
  return 0;
}