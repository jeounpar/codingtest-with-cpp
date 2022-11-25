#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int k, l;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> l;
	unordered_map<string, int> us;
	for (int i = 0; i < l; i++)
	{
		string s;
		cin >> s;
		if (us.find(s) == us.end())
			us[s] = i;
		else
		{
			us.erase(s);
			us[s] = i;
		}
	}
	int cnt = 0;
	// for (auto a : us)
	// 	cout << a.first << " " << a.second << "\n";
	vector<pair<int, string>> vc;
	for (auto a : us)
		vc.push_back({a.second, a.first});
	// cout << "\n";
	sort(vc.begin(), vc.end());
	int ed = min(k, (int)vc.size());
	for (int i = 0; i < ed; i++)
		cout
				<< vc[i].second << "\n";
	return 0;
}