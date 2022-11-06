#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		int a;
		vector<int> vc;
		for (int i = 0; i < n; i++)
		{
			cin >> a;
			vc.push_back(a);
		}
		reverse(vc.begin(), vc.end());
		int max_val = vc[0];
		long long ans = 0;
		for (int i = 1; i < n; i++)
		{
			if (vc[i] > max_val)
				max_val = vc[i];
			else
				ans += max_val - vc[i];
		}
		cout << ans << "\n";
	}
	return 0;
}