#include <bits/stdc++.h>

using namespace std;

bool cmp(const string &a, const string &b)
{
	return a.length() < b.length();
}

bool cmp2(const string &a, const string &b)
{
	return a < b;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<string> vc;
	while (n--)
	{
		string s;
		cin >> s;
		vc.push_back(s);
	}
	sort(vc.begin(), vc.end(), cmp2);
	sort(vc.begin(), vc.end(), cmp);
	vc.erase(unique(vc.begin(), vc.end(), vc.end()));
	for (auto a : vc)
		cout << a << "\n";
	return 0;
}