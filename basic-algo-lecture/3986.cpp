#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	int ans = 0;
	while (n--)
	{
		stack<char> st;
		string t;
		cin >> t;
		for (auto c : t)
		{
			if (!st.empty() && st.top() == c)
				st.pop();
			else
				st.push(c);
		}
		if (st.empty())
			ans++;
	}
	cout << ans << "\n";
	return 0;
}