#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void setZeroes(vector<vector<int>> &matrix) {
  int m = matrix.size();
  int n = matrix[0].size();
  vector<pair<int, int>> vc;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      if (matrix[i][j] == 0)
        vc.push_back({i, j});
    }
  }

  for (auto a : vc) {
    for (int i = 0; i < n; i++)
      matrix[a.first][i] = 0;
    for (int i = 0; i < m; i++)
      matrix[i][a.second] = 0;
  }
}
