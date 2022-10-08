#include <bits/stdc++.h>

using namespace std;

vector<int> vc;
vector<int> ans;
int n, m;
bool ok[9];

void solve(int idx, int pre)
{
	if (idx == m)
	{
		for (auto a : ans)
			cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (ok[i] || (pre > vc[i]))
			continue;
		ans.push_back(vc[i]);
		ok[i] = true;
		solve(idx + 1, vc[i]);
		ans.pop_back();
		ok[i] = false;
	}
}
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		vc.push_back(t);
	}
	sort(vc.begin(), vc.end());
	solve(0, 0);
	return 0;
}