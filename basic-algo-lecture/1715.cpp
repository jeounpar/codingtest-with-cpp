#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--)
	{
		int t;
		cin >> t;
		pq.push(t);
	}
	int ans = 0;
	while (pq.size() > 1)
	{
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += (a + b);
		pq.push(a + b);
	}
	cout << ans;
	return 0;
}