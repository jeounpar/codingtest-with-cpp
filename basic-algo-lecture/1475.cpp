#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int ans = 0;
	int a[10] = {0};

	cin >> n;
	while (n > 0) {
		int b = n % 10;
		n = n / 10;
		a[b] += 1;
	}
	int k = a[6] + a[9];
	
	cout << ans << "\n";
	return 0;
}