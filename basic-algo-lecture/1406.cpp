#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <list>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	list<char> str;
	string s;
	cin >> s;
	for (auto c : s)
		str.push_back(c);
	auto curr = str.end();
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char op, c;
		cin >> op;
		if (op == 'P')
		{
			cin >> c;
			str.insert(curr, c);
		}
		else if (op == 'L')
		{
			if (curr != str.begin())
				curr--;
		}
		else if (op == 'D')
		{
			if (curr != str.end())
				curr++;
		}
		else
		{
			if (curr != str.begin())
			{
				curr--;
				curr = str.erase(curr);
			}
		}
	}

	for (auto c : str)
		cout << c;
	cout << "\n";

	return 0;
}