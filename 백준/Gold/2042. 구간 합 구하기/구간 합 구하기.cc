#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m, k;
ll arr[1000001];
ll seg[1001];

int sq;

void init() {
  sq = sqrt(n);
  for (int i = 1; i <= n; i++) {
    seg[i / sq] += arr[i];
  }
}

void update(int idx, ll val) {
  int id = idx / sq;
  seg[id] -= arr[idx];
  seg[id] += val;
  arr[idx] = val;
}

ll query(int l, int r) {
  ll rst = 0;
  while (l % sq != 0 && l <= r) {
    rst += arr[l];
    l++;
  }
  while ((r + 1) % sq != 0 && l <= r) {
    rst += arr[r];
    r--;
  }
  while (l <= r) {
    rst += seg[l / sq];
    l += sq;
  }
  return rst;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    cin >> arr[i];
  ll a, b, c;
  init();
  for (int i = 0; i < m + k; i++) {
    cin >> a >> b >> c;
    if (a == 1)
      update(b, c);
    else
      cout << query(b, c) << "\n";
  }
  return 0;
}