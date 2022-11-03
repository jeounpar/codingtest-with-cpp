#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int s[100001];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	// d[i] = s[i] 로 끝나는 합의 최대값
	int d[100001];
	d[1] = s[1];
	for (int i = 2; i <= n; i++)
	{
		d[i] = s[i];
		d[i] = max(d[i - 1] + s[i], d[i]);
	}
	int ans = d[1];
	for (int i = 2; i <= n; i++)
		ans = max(ans, d[i]);
	cout << ans;
	return 0;
}
