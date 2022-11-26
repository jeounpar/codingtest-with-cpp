#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k;
vector<pair<int, int>> jump;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int a, b;
		cin >> a >> b;
		if (b <= a)
			continue;
		jump.push_back({a, b});
	}
	int st = 0;
	int ans = 0;
	while (st < n - 1)
	{
		// cout << "st = " << st << "\n";
		// cout << "ans = " << ans << "\n";
		int flag = 0;
		for (int i = 0; i < jump.size(); i++)
		{
			auto cur = jump[i];
			int x = cur.first;
			int y = cur.second;
			if (x >= st && x <= st + 6)
			{
				st = y;
				ans++;
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			continue;
		else
		{
			st += 6;
			ans++;
		}
		if (ans >= 1000000)
		{
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << ans << "\n";
	return 0;
}