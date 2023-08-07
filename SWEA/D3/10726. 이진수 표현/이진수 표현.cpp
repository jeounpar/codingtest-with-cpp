#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int answer = 0;
int n, m;

void solve(int test_case) {
  answer = 0;
  cin >> n >> m;
  int mask = (1 << n) - 1;
  int rst = mask & m;
  if (rst != mask) {
    cout << "#" << test_case << " OFF"
         << "\n";
  } else {
    cout << "#" << test_case << " ON"
         << "\n";
  }
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