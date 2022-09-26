#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int t[16];
int p[16];
int n;
int ans = 0;

void solve(int day, int sum)
{
	if (day > n + 1) return;
	if (day == n + 1) {
		if (sum > ans) {
			ans = sum;
		}
		return;
	}
	solve(day + 1, sum);
	solve(day + t[day], sum + p[day]);
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		t[i] = a;
		p[i] = b;
	}
	solve(1, 0);
	cout << ans << '\n';
	return 0;
}