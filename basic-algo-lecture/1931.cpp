#include <bits/stdc++.h>

using namespace std;

bool compare(pair<int, int> v1, pair<int, int> v2)
{
	if (v1.second == v2.second)
		return v1.first < v2.first;
	return v1.second < v2.second;
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<pair<int, int>> vc;
	int min_end = INT_MAX;
	int min_idx = 0;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		cin >> a >> b;
		vc.push_back({a, b});
	}
	sort(vc.begin(), vc.end(), compare);
	int ans = 1;
	int pre_end = vc[0].second;
	for (int i = 1; i < n; i++)
	{
		if (vc[i].first >= pre_end)
		{
			ans++;
			pre_end = vc[i].second;
		}
	}
	cout << ans << "\n";
	return 0;
}