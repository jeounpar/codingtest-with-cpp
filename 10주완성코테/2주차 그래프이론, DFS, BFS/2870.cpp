#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;

bool cmp(string a, string b) {
  if (a.size() == b.size())
    return a < b;
  return a.size() < b.size();
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  string s;
  vector<string> ans;
  while (n--) {
    cin >> s;
    string tmp = "";
    bool flag = true;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c >= '0' && c <= '9')
        tmp += c;
      else {
        if (tmp.size() > 0) {
          ans.push_back(tmp);
          tmp = "";
        }
      }
      if (i + 1 == s.size() && tmp.size() > 0)
        ans.push_back(tmp);
    }
  }
  for (int i = 0; i < ans.size(); i++) {
    int cnt = 0;
    for (int j = 0; j < ans[i].size(); j++) {
      if (ans[i][j] == '0')
        cnt++;
      else
        break;
    }
    if (cnt == ans[i].size())
      cnt--;
    ans[i] = ans[i].substr(cnt);
  }
  sort(ans.begin(), ans.end(), cmp);
  for (auto str : ans)
    cout << str << "\n";
  return 0;
}