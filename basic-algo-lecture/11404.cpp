#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int dist[101][101];
int INF = 0x3f3f3f3f;

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      dist[i][j] = INF;

  int a, b, c;
  for (int i = 0; i < m; i++) {
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
  }

  for (int i = 1; i <= n; i++) {
    dist[i][i] = 0;
  }

  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == INF)
        cout << "0 ";
      else
        cout << dist[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}