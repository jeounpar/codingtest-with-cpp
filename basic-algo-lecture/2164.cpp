#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	deque<int> vc;
	for (int i = n; i >= 1; i--)
		vc.push_back(i);
	while (vc.size() != 1)
	{
		int top;
		vc.pop_back();
		top = vc[vc.size() - 1];
		vc.pop_back();
		vc.push_front(top);
	}
	cout << vc[0] << "\n";
	return 0;
}