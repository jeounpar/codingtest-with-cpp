#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t, n, m;
int arr[1001];
int brr[1001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> m;
  for (int i = 0; i < m; i++)
    cin >> brr[i];
  vector<int> vc;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int sum = 0;
      for (int t = i; t <= j; t++)
        sum += arr[t];
      vc.push_back(sum);
    }
  }
  sort(vc.begin(), vc.end());

  // vc.erase(unique(vc.begin(), vc.end()), vc.end());

  vector<int> vc2;
  for (int i = 0; i < m; i++) {
    for (int j = i; j < m; j++) {
      int sum = 0;
      for (int t = i; t <= j; t++)
        sum += brr[t];
      vc2.push_back(sum);
    }
  }
  sort(vc2.begin(), vc2.end());
  // vc2.erase(unique(vc2.begin(), vc2.end()), vc2.end());

  ll cnt = 0;
  for (auto a : vc) {
    cnt += upper_bound(vc2.begin(), vc2.end(), t - a) -
           lower_bound(vc2.begin(), vc2.end(), t - a);
  }
  cout << cnt;
  return 0;
}