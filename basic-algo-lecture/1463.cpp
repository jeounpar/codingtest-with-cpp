#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int ans = INT_MAX;
	cin >> n;

	int d[1000001];
	d[1] = 0;
	for (int i = 2; i < 1000001; i++)
	{
		d[i] = d[i - 1] + 1;
		if (i % 2 == 0)
			d[i] = min(d[i], d[i / 2] + 1);
		if (i % 3 == 0)
			d[i] = min(d[i], d[i / 3] + 1);
	}
	cout << d[n] << "\n";
	return 0;
}