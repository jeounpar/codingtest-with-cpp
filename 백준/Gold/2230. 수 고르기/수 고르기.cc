#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n, m;
int a[100001];

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int ans = INT_MAX;
	int ed = 0;
	for (int st = 0; st < n; st++)
	{
		while (ed < n && a[ed] - a[st] < m)
			ed++;
		if (ed == n)
			break;
		ans = min(ans, a[ed] - a[st]);
	}
	cout << ans;
	return 0;
}