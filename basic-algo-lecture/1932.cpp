#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int s[501][501];
	int d[501][501];

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> s[i][j];
	d[1][1] = s[1][1];
	for (int i = 2; i <= n; i++)
		for (int j = 1; j <= i; j++)
			d[i][j] = max(d[i - 1][j], d[i - 1][j - 1]) + s[i][j];
	int ans = -1;
	for (int j = 1; j <= n; j++)
		ans = max(ans, d[n][j]);
	cout << ans;
	return 0;
}