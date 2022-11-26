#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string shared_pw;
	int n;
	cin >> shared_pw;
	cin >> n;
	vector<pair<int, string>> vc;
	for (int i = 0; i < n; i++)
	{
		int a;
		string b;
		cin >> a >> b;
		vc.push_back({a, b});
	}
	string s;
	cin >> s;
	cout << "\n s = " << s;
	return 0;
}