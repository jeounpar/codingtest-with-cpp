#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
int op_nums = 0;
vector<int> vc;
vector<int> ans;
int a[12];
int op[4];

void solve(int idx)
{
	if (idx == op_nums) {
		int sum = a[0];
		for (int i = 0; i < n - 1; i++) {
			int k = vc[i];
			if (k == 0) sum = sum + a[i + 1];
			else if (k == 1) sum = sum - a[i + 1];
			else if (k == 2) sum = sum * a[i + 1];
			else sum = sum / a[i + 1];
		}
		ans.push_back(sum);
		return ;
	}
	for (int i = 0; i < 4; i++) {
		if (op[i] > 0) {
			vc.push_back(i);
			op[i] -= 1;
			solve(idx + 1);
			vc.pop_back();
			op[i] += 1;
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
		op_nums += op[i];
	}
	solve(0);
	sort(ans.begin(), ans.end());
	cout << ans[ans.size() - 1] << "\n";
	cout << ans[0] << "\n";
} 