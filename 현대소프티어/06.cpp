#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> vc;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	while (!cin.eof())
	{
		int num;
		cin >> num;
		vc.push_back(num);
		// cout << num << "\n";
	}
	sort(vc.begin(), vc.end());
	int len = INT_MAX;
	vector<tuple<ll, ll, ll>> ans;
	for (int i = 0; i < vc.size() - 1; i++)
	{

		len = min(len, abs(vc[i] - vc[i + 1]));
		ans.push_back({abs(vc[i] - vc[i + 1]), vc[i], vc[i + 1]});
	}
	for (auto a : ans)
	{
		int x, y, z;
		tie(x, y, z) = a;
		if (x == len)
		{
			cout << y << " " << z << "\n";
			return 0;
		}
		// cout << x << " " << y << " " << z << "\n";
	}
	return 0;
}