#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vc;

	for (int i = 0; i < 3; i++) {
		int a;
		cin >> a;
		vc.push_back(a);
	}
	sort(vc.begin(), vc.end());
	cout << vc[0] << " " << vc[1] << " " << vc[2] << "\n";
	return 0;
}