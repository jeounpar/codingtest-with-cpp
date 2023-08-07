#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve(int test_case) {
  int answer = 0;
  int n;
  unordered_set<char> us;
  cin >> n;
  int t = 0;
  int k = n;
  while (true) {
    string s = to_string(k);
    int slen = s.length();
    for (int i = 0; i < slen; i++) {
      us.insert(s[i]);
    }
    if (us.size() == 10)
      break;
    t++;
    k = n * t;
  }
  cout << "#" << test_case << " " << k << "\n";
}

int main(int argc, char **argv) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int test_case;
  int T;
  cin >> T;
  for (test_case = 1; test_case <= T; ++test_case) {
    solve(test_case);
  }
  return 0;
}