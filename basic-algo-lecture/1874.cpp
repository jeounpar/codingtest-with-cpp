#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	stack<int> st;
	st.push(0);
	string ans;
	int idx = 1;
	bool ok = true;
	while (n--)
	{
		int t;
		cin >> t;
		while (idx <= t)
		{
			st.push(idx);
			ans += "+\n";
			idx++;
		}
		if (st.top() == t)
		{
			st.pop();
			ans += "-\n";
		}
		else
			ok = false;
	}
	if (ok)
		cout << ans;
	else
		cout << "NO\n";
	return 0;
}