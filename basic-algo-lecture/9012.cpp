#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	while (n--)
	{
		string s;
		stack<char> st;
		cin >> s;
		bool is_valid = true;
		for (auto c : s)
		{
			if (c == '(')
				st.push(c);
			else
			{
				if (st.empty() || st.top() != '(')
				{
					is_valid = false;
					break;
				}
				else
					st.pop();
			}
		}
		if (!st.empty())
			is_valid = false;
		if (is_valid)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}
