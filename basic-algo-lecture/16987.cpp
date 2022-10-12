#include <bits/stdc++.h>

using namespace std;
int n;
int s[10]; // 내구도
int w[10]; // 무게
int ans = 0;
int cnt = 0;

void solve(int k)
{
	if (k == n)
	{
		ans = max(ans, cnt);
		return;
	}
	if (s[k] <= 0 || cnt == n - 1)
	{
		solve(k + 1);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == k || s[i] <= 0)
			continue;
		s[k] -= w[i];
		s[i] -= w[k];
		if (s[k] <= 0)
			cnt++;
		if (s[i] <= 0)
			cnt++;
		solve(k + 1);
		if (s[k] <= 0)
			cnt--;
		if (s[i] <= 0)
			cnt--;
		s[k] += w[i];
		s[i] += w[k];
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i] >> w[i];
	solve(0);
	cout << ans << "\n";
	return 0;
}