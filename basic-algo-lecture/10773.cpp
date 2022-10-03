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

	int k;
	int a;
	cin >> k;
	vector<int> vc;
	while (k--)
	{
		cin >> a;
		if (a == 0)
			vc.pop_back();
		else
			vc.push_back(a);
	}
	int ans = 0;
	for (auto t : vc)
		ans += t;
	cout << ans << "\n";
}