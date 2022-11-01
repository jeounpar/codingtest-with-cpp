#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;

	int d[41][2];

	d[0][0] = 1;
	d[1][1] = 1;
	for (int i = 1; i < 41; i++)
	{
		d[i][0] = d[i - 1][0] + d[i - 2][0];
		d[i][1] = d[i - 1][1] + d[i - 2][1];
	}
	while (t--)
	{
		int a;
		cin >> a;
		cout << d[a][0] << " " << d[a][1] << "\n";
	}

	return 0;
}