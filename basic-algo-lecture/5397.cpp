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

	int t;
	cin >> t;
	while (t--)
	{
		list<char> l;
		auto curr = l.begin();
		string s;
		cin >> s;
		for (auto c : s)
		{
			if (c == '<')
			{
				if (curr != l.begin())
					curr--;
			}
			else if (c == '>')
			{
				if (curr != l.end())
					curr++;
			}
			else if (c == '-')
			{
				if (curr != l.begin())
				{
					curr--;
					curr = l.erase(curr);
				}
			}
			else
				l.insert(curr, c);
		}
		for (auto c : l)
			cout << c;
		cout << "\n";
	}
}