#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int a[1000001];

bool solve(ll x)
{
	ll cur = 0;
	for (int i = 0; i < n; i++)
	{
		ll tmp;
		tmp = a[i] - x;
		if (tmp > 0)
			cur += tmp;
	}
	return cur >= m;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
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