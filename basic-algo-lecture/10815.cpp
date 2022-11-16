#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	vector<int> a;
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	int m;
	cin >> m;
	vector<int> b;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		b.push_back(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		auto ans = binary_search(a.begin(), a.end(), b[i]);
		cout << ans << " ";
	}
	return 0;
}