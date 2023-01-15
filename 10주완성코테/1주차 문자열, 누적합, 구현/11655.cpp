#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  string s;
  getline(cin, s);
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = (s[i] - 'a' + 13) % 26 + 'a';
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = (s[i] - 'A' + 13) % 26 + 'A';
    }
  }
  cout << s;
  return 0;
}