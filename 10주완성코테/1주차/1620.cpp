#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  unordered_map<string, int> M;
  unordered_map<int, string> M2;
  for (int i = 1; i <= n; i++) {
    string str;
    cin >> str;
    M[str] = i;
    M2[i] = str;
  }
  for (int i = 0; i < m; i++) {
    string s;
    cin >> s;
    int a;
    if (s[0] >= '0' && s[0] <= '9') {
      a = stoi(s);
      cout << M2[a] << "\n";
    } else {
      cout << M[s] << "\n";
    }
  }

  return 0;
}