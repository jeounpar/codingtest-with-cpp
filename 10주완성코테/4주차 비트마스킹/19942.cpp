#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int mp, mf, ms, mv;
vector<int> vc[20];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  cin >> mp >> mf >> ms >> mv;
  int t;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> t;
      vc[i].push_back(t);
    }
  }
  int ans = INT_MAX;
  vector<vector<int>> arr;
  for (int i = 0; i < (1 << n); i++) {
    int a = 0, b = 0, c = 0, d = 0, sum = 0;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        a += vc[j][0];
        b += vc[j][1];
        c += vc[j][2];
        d += vc[j][3];
        sum += vc[j][4];
      }
    }
    if (a >= mp && b >= mf && c >= ms && d >= mv && sum <= ans) {
      vector<int> tmp;
      ans = sum;
      tmp.push_back(ans);
      for (int j = 0; j < n; j++) {
        if (i & (1 << j))
          tmp.push_back(j + 1);
      }
      arr.push_back(tmp);
    }
  }
  if (ans == INT_MAX)
    cout << -1;
  else {
    sort(arr.begin(), arr.end());
    cout << arr[0][0] << "\n";
    for (int i = 1; i < arr[0].size(); i++)
      cout << arr[0][i] << " ";
  }
  return 0;
}