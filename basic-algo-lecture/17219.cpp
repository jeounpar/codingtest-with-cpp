#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	unordered_map<string, string> us;
	for (int i = 0; i < n; i++)
	{
		string a, b;
		cin >> a >> b;
		us[a] = b;
	}
	for (int i = 0; i < m; i++)
	{
		string a;
		cin >> a;
		cout << us[a] << "\n";
	}
	return 0;
}