#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, c;
int a[200001];

bool solve(int len)
{
	int idx = 0;
	int cnt = 0;
	while (idx < n)
	{
		idx = lower_bound(a + idx, a + n, a[idx] + len) - a;
		cnt++;
	}
	return cnt >= c;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> c;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	ll ans = INT_MAX;
	int st = 1;
	int ed = 1000000000;
	while (st < ed)
	{
		int mid = (st + ed + 1) / 2;
		// cout << mid << "\n";
		if (solve(mid))
			st = mid;
		else
			ed = mid - 1;
	}
	cout << st;
	return 0;
}