#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, m;
	cin >> n >> m;
	int s[100001];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	int d[100001];
	d[1] = s[1];
	for (int i = 2; i <= n; i++)
		d[i] = d[i - 1] + s[i];
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		cout << d[b] - d[a - 1] << "\n";
	}
	return 0;
}