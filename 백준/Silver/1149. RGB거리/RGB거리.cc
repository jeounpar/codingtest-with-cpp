#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int s[1001][3];
	int a, b, c;
	for (int i = 1; i <= n; i++)
	{
		cin >> a >> b >> c;
		s[i][0] = a;
		s[i][1] = b;
		s[i][2] = c;
	}
	int d[1005][3];
	d[1][0] = s[1][0];
	d[1][1] = s[1][1];
	d[1][2] = s[1][2];
	for (int i = 2; i < 1001; i++)
	{
		d[i][0] = min(d[i - 1][1], d[i - 1][2]) + s[i][0];
		d[i][1] = min(d[i - 1][0], d[i - 1][2]) + s[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][0]) + s[i][2];
	}
	cout << min(d[n][0], min(d[n][1], d[n][2]));
	return 0;
}