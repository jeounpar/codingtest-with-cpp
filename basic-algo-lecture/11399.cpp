#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int s[1001];
	for (int i = 1; i <= n; i++)
		cin >> s[i];
	sort(s, s + n + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++)
		ans += s[i] * (n - i + 1);
	cout << ans;
	return 0;
}
