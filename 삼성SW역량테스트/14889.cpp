#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int arr[21][21];
int ans = 214;
vector<int> x;
vector<int> y;

void solve(int idx, vector<int> x, vector<int> y)
{
	if (idx == n) {
		if (x.size() != n / 2 || y.size() != n / 2 ) return;
		if (x.size() == n / 2 && y.size() == n / 2) {
			int a = 0, b = 0;
			for (int i = 0; i < n / 2; i++) {
				for (int j = 0; j < n / 2; j++) {
					if (i == j) continue;
					a += arr[x[i]][x[j]];
					b += arr[y[i]][y[j]];
				}
			}
			int rst = abs(a - b);
			if (rst < ans) ans = rst;
			return ;
		}
	}

	x.push_back(idx);
	solve(idx + 1, x, y);
	x.pop_back();
	y.push_back(idx);
	solve(idx + 1 ,x, y);
	y.pop_back();
	return ;
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	
	solve(0, x, y);

	cout << ans << "\n";
	return 0;
}