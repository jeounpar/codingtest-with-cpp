#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, b, c;
int arr[1000001];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  cin >> b >> c;

  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    arr[i] -= b;
    ans++;
  }
  for (int i = 1; i <= n; i++) {
    if (arr[i] > 0) {
      ans += arr[i] / c;
      if (arr[i] % c > 0) {
        ans++;
      }
    }
  }
  cout << ans;
  return 0;
}