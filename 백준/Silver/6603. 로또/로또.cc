#include <bits/stdc++.h>

using namespace std;

int k;
int arr[15];
bool ok[15];

void solve(int idx, int pre, vector<int> &ans)
{
	if (idx == 6)
	{
		for (int i = 0; i < 6; i++)
			cout << ans[i] << " ";
		cout << "\n";
		return;
	}
	for (int i = 0; i < k; i++)
	{
		if (ok[i] || pre > arr[i])
			continue;
		ok[i] = true;
		ans.push_back(arr[i]);
		solve(idx + 1, arr[i], ans);
		ok[i] = false;
		ans.pop_back();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	while (true)
	{
		cin >> k;
		if (k == 0)
			break;
		int tmp;
		vector<int> ans;
		fill(arr, arr + 15, 0);
		fill(ok, ok + 15, false);
		for (int i = 0; i < k; i++)
		{
			cin >> tmp;
			arr[i] = tmp;
		}
		solve(0, 0, ans);
		cout << "\n";
	}
	return 0;
}
