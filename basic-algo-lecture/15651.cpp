#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> vc;

void solve(int idx)
{
	if (idx == m)
	{
		for (auto a : vc)
			cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		vc.push_back(i);
		solve(idx + 1);
		vc.pop_back();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	solve(0);
	return 0;
}