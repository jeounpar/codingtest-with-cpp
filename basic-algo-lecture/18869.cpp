#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int m, n;
int a[101][10001];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	for (int k = 0; k < m; k++)
	{
		vector<int> vc(a[k], a[k] + n);
		sort(vc.begin(), vc.end());
		vc.erase(unique(vc.begin(), vc.end()), vc.end());
		for (int i = 0; i < n; i++)
		{
			a[k][i] = lower_bound(vc.begin(), vc.end(), a[k][i]) - vc.begin();
			// cout << a[k][i] << " ";
		}
		// cout << "\n";
	}
	int ans = 0;
	for (int i = 0; i < m - 1; i++)
	{
		for (int j = i + 1; j < m; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (a[i][k] != a[j][k])
					break;
				if (k + 1 == n)
					ans++;
			}
		}
	}
	cout << ans;
	return 0;
}