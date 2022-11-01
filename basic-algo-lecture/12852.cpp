#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int d[1000001];
	d[1] = 0;
	int pre[1000001];
	for (int i = 2; i < 1000001; i++)
	{
		d[i] = d[i - 1] + 1;
		pre[i] = i - 1;
		if (i % 3 == 0 && d[i] > d[i / 3] + 1)
		{
			d[i] = d[i / 3] + 1;
			pre[i] = i / 3;
		}
		if (i % 2 == 0 && d[i] > d[i / 2] + 1)
		{
			d[i] = d[i / 2] + 1;
			pre[i] = i / 2;
		}
	}
	cout << d[n] << "\n";
	int curr = n;
	while (true)
	{
		cout << curr << " ";
		if (curr == 1)
			break;
		curr = pre[curr];
	}
	return 0;
}