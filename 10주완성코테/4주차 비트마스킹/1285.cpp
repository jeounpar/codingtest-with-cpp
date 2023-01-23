#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<string> vc;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vc.push_back(s);
  }

  return 0;
}