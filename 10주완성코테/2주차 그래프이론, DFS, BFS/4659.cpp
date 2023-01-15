#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string s;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  while (true) {
    cin >> s;
    if (s.compare("end") == 0)
      break;
    vector<vector<int>> vc(2);           //	2번
    unordered_map<char, vector<int>> M2; // 3번
    bool one_flag = false;
    for (int i = 0; i < s.size(); i++) {
      char c = s[i];
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        one_flag = true;
        vc[0].push_back(i);
      } else {
        vc[1].push_back(i);
      }
      M2[c].push_back(i);
    }

    if (!one_flag) {
      cout << "<" << s << "> is not acceptable.\n";
      continue;
    }
    bool flag = true;
    if (vc[0].size() >= 3) {
      for (int i = 0; i <= vc[0].size() - 3; i++) {
        if ((vc[0][i + 1] - vc[0][i] == 1) &&
            (vc[0][i + 2] - vc[0][i + 1] == 1)) {
          cout << "<" << s << "> is not acceptable.\n";
          flag = false;
          break;
        }
      }
    }
    if (!flag)
      continue;
    flag = true;
    if (vc[1].size() >= 3) {
      for (int i = 0; i <= vc[1].size() - 3; i++) {
        if ((vc[1][i + 1] - vc[1][i] == 1) &&
            (vc[1][i + 2] - vc[1][i + 1] == 1)) {
          cout << "<" << s << "> is not acceptable.\n";
          flag = false;
          break;
        }
      }
    }
    if (!flag)
      continue;
    flag = true;
    for (auto a : M2) {
      if (a.second.size() <= 1 || a.first == 'e' || a.first == 'o')
        continue;
      for (int i = 0; i <= a.second.size() - 2; i++) {
        if (a.second[i] + 1 == a.second[i + 1]) {
          cout << "<" << s << "> is not acceptable.\n";
          flag = false;
          break;
        }
      }
    }
    if (!flag)
      continue;
    cout << "<" << s << "> is acceptable.\n";
  }
  return 0;
}