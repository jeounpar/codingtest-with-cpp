#include <bits/stdc++.h>

using namespace std;

int n, m;
bool ok[9];
vector<int> vc;

void solve(int index)
{
	if (index == m)
	{
		for (auto a : vc)
			cout << a << " ";
		cout << "\n";
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (ok[i])
			continue;
		ok[i] = true;
		vc.push_back(i);
		solve(index + 1);
		ok[i] = false;
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