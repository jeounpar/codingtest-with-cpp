#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
int a[10001];

bool solve(ll x)
{
	ll cur = 0;
	for (int i = 0; i < k; i++)
		cur += a[i] / x;
	return cur >= n;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> n;
	for (int i = 0; i < k; i++)
		cin >> a[i];
	ll st = 1;
	ll ed = INT_MAX;
	while (st < ed)
	{
		ll mid = (st + ed + 1) / 2;
		// cout << st << " " << mix << " " << ed << "\n";
		if (solve(mid))
			st = mid;
		else
			ed = mid - 1;
	}
	cout << st;
	return 0;
}