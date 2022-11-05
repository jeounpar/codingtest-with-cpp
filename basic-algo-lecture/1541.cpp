#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int sum = 0;
	int ans = 0;
	int sign = 1;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == '-' || s[i] == '+')
		{
			ans += sum * sign;
			if (s[i] == '-')
				sign = -1;
			sum = 0;
		}
		else
			sum = sum * 10 + (s[i] - '0');
	}
	ans += sum * sign;
	cout << ans;
	return 0;
}