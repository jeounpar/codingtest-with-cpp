#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int dp[301][301];
int solution(int alp, int cop, vector<vector<int>> problems) {
  int goal_a = 0;
  int goal_c = 0;
  for (int i = 0; i < problems.size(); i++) {
    goal_a = max(problems[i][0], goal_a);
    goal_c = max(problems[i][1], goal_c);
  }
  if (goal_a <= alp && goal_c <= cop) {
    return 0;
  }
  if (alp >= goal_a) {
    alp = goal_a;
  }
  if (cop >= goal_c) {
    cop = goal_c;
  }
  int dp[501][501];
  for (int i = alp; i <= goal_a; i++) {
    for (int j = cop; j <= goal_c; j++) {
      dp[i][j] = INT_MAX;
    }
  }
  dp[alp][cop] = 0;
  for (int i = alp; i <= goal_a; i++) {
    for (int j = cop; j <= goal_c; j++) {
      dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1);
      dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);
      for (auto p : problems) {
        if (i >= p[0] && j >= p[1]) {
          if (i + p[2] > goal_a && j + p[3] > goal_c) {
            dp[goal_a][goal_c] = min(dp[goal_a][goal_c], dp[i][j] + p[4]);
          } else if (i + p[2] > goal_a) {
            dp[goal_a][j + p[3]] = min(dp[goal_a][j + p[3]], dp[i][j] + p[4]);
          } else if (j + p[3] > goal_c) {
            dp[i + p[2]][goal_c] = min(dp[i + p[2]][goal_c], dp[i][j] + p[4]);
          } else if (i + p[2] <= goal_a && j + p[3] <= goal_c) {
            dp[i + p[2]][j + p[3]] =
                min(dp[i + p[2]][j + p[3]], dp[i][j] + p[4]);
          }
        }
      }
    }
  }
  return dp[goal_a][goal_c];
}