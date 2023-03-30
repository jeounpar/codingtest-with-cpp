#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
unordered_map<string, int> M;
vector<int> adj[1001];
int ind[1001];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    M[s] = i;
  }
  cin >> m;
  string a, b;
  int x, y;
  for (int i = 0; i < m; i++) {
    cin >> a >> b;
    x = M[a];
    y = M[b];
    adj[x].push_back(y);
    ind[y] += 1;
  }

  return 0;
}