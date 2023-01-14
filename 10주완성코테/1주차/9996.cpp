#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  int n;
  cin >> n;
  string pat;
  cin >> pat;
  auto idx = pat.find("*");
  string left = pat.substr(0, idx);
  string right = pat.substr(idx + 1);
  reverse(right.begin(), right.end());
  string str;
  while (n--) {
    int cnt = 0;
    cin >> str;
    if (str.size() < pat.size() - 1) {
      cout << "NE\n";
      continue;
    }
    bool flag = true;
    for (int i = 0; i < left.size(); i++) {
      if (str[i] != left[i]) {
        flag = false;
        break;
      }
    }
    if (flag)
      cnt++;
    flag = true;
    reverse(str.begin(), str.end());
    for (int i = 0; i < right.size(); i++) {
      if (str[i] != right[i]) {
        flag = false;
        break;
      }
    }
    if (flag)
      cnt++;
    // cout << cnt;
    if (cnt == 2)
      cout << "DA\n";
    else
      cout << "NE\n";
  }
  return 0;
}