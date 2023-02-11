#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, x;
int arr[100001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  cin >> x;
  sort(arr, arr + n);
  int l = 0, r = n - 1;
  ll ans = 0;
  while (l < r && r <= n) {
    int sum = arr[l] + arr[r];
    if (sum == x) {
      ans++;
      r--;
    } else if (sum < x)
      l++;
    else
      r--;
  }
  cout << ans;
  return 0;
}