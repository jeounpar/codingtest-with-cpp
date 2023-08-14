#include <bits/stdc++.h>

using namespace std;
int n, m;
char board[1001][1001];
int dist[1001][1001][2];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> board[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			dist[i][j][0] = dist[i][j][1] = -1;
	dist[1][1][0] = 1;
	dist[1][1][1] = 1;
	queue<tuple<int, int, int>> Q;
	Q.push({1, 1, 0});
	while (!Q.empty())
	{
		int x, y, broken;
		tie(x, y, broken) = Q.front();
		if (x == n && y == m)
		{
			cout << dist[x][y][broken];
			return 0;
		}
		Q.pop();
		int next_dist = dist[x][y][broken] + 1;
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > m)
				continue;
			if (board[nx][ny] == '0' && dist[nx][ny][broken] == -1)
			{
				dist[nx][ny][broken] = next_dist;
				Q.push({nx, ny, broken});
			}
			if (!broken && board[nx][ny] == '1' && dist[nx][ny][1] == -1)
			{
				dist[nx][ny][1] = next_dist;
				Q.push({nx, ny, 1});
			}
		}
	}
	cout << -1 << "\n";
	return 0;
}