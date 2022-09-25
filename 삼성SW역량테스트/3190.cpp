#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long long int n, b, c, ans;
	
	ans = 0;
	vector<long long int> v;
	v.push_back(-1);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}
	cin >> b;
	cin >> c;

	for (int i = 1; i <= n; i++) {
		int tmp;
		tmp = v[i];
		tmp -= b;
		ans += 1;
		if (tmp < 0) continue;
		ans += tmp / c;
		if (tmp % c != 0) {
			ans += 1;
		}
	}
	cout << ans << '\n';
	return 0;
}