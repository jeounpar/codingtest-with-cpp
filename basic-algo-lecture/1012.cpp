#include <bits/stdc++.h>

using namespace std;

queue<pair<int, int>> q;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int m, n, k;
int arr[51][51];
bool ok[51][51];

void solve(int x, int y)
{
	ok[x][y] = true;
	q.push({x, y});
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (ok[nx][ny] || arr[nx][ny] != 1)
				continue;
			ok[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	return;
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> m >> n >> k;
		while (k--)
		{
			int x, y;
			cin >> x >> y;
			arr[y][x] = 1;
		}
		int ans = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && !ok[i][j])
				{
					solve(i, j);
					ans++;
				}
			}
		}
		cout << ans << "\n";
		for (int i = 0; i < n; i++)
		{
			fill(arr[i], arr[i] + m, 0);
			fill(ok[i], ok[i] + m, false);
		}
	}
	return 0;
}