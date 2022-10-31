#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;

	cin >> n;
	vector<long long> vc;
	while (n--)
	{
		long long num;
		string s;
		cin >> s;
		reverse(s.begin(), s.end());
		const char *c = s.c_str();
		num = atoll(c);
		vc.push_back(num);
	}
	sort(vc.begin(), vc.end());
	for (auto a : vc)
		cout << a << "\n";
	return 0;
}