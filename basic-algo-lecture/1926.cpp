#include <bits/stdc++.h>

using namespace std;

int draw_cnt = 0;
int draw_area = 0;
int n, m;
bool ok[501][501];
int s[501][501];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

void solve(int x, int y)
{
	int area = 0;

	draw_cnt++;
	queue<pair<int, int>> q;
	q.push({x, y});
	ok[x][y] = true;
	while (!q.empty())
	{
		area++;
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (ok[nx][ny] || s[nx][ny] != 1)
				continue;
			ok[nx][ny] = true;
			q.push({nx, ny});
		}
	}
	draw_area = max(draw_area, area);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> s[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (s[i][j] != 1 || ok[i][j])
				continue;
			solve(i, j);
		}
	}
	cout << draw_cnt << "\n"
			 << draw_area << "\n";
	return 0;
}