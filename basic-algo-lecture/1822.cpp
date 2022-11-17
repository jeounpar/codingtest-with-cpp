#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	int a[500001];
	int b[500001];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < m; i++)
		cin >> b[i];
	sort(b, b + m);
	vector<int> ans;
	for (int i = 0; i < n; i++)
	{
		auto find = binary_search(b, b + m, a[i]);
		if (!find)
		{
			ans.push_back(a[i]);
			continue;
		}
	}
	cout << ans.size() << "\n";
	if (ans.size() != 0)
	{
		for (auto asd : ans)
			cout << asd << " ";
	}
	return 0;
}