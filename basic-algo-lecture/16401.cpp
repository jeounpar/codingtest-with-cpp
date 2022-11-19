#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int m, n;
int a[1000001];

bool solve(ll x)
{
	if (x == 0)
		return true;
	ll cur = 0;
	for (int i = 0; i < n; i++)
		cur += a[i] / x;
	return cur >= m;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	ll st = 0;
	ll ed = *max_element(a, a + n);
	while (st < ed)
	{
		ll mid = (st + ed + 1) / 2;
		if (solve(mid))
			st = mid;
		else
			ed = mid - 1;
	}
	cout << st;
	return 0;
}