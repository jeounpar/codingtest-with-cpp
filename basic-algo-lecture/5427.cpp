#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
int w, h;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--)
	{
		char board[1001][1001];
		int dist[1001][1001] = {
				0,
		};
		cin >> w >> h;
		queue<pair<int, int>> sang;
		queue<pair<int, int>> fire;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == '@')
					sang.push({i, j});
				if (board[i][j] == '*')
					fire.push({i, j});
				if (board[i][j] == '*')
					dist[i][j] = -1;
			}
		}
		while (!fire.empty())
		{
			// cout << "asd\n";
			auto cur = fire.front();
			fire.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx > h || ny < 0 || ny > w)
					continue;
				if (board[nx][ny] == '#' || dist[nx][ny] == 0)
					continue;
				fire.push({nx, ny});
				dist[nx][ny] = dist[cur.first][cur.second] - 1;
			}
		}
		for (int i = 0; i < h; i++)
			for (int j = 0; j < w; j++)
				dist[i][j] = -1;
		dist[sang.front().first][sang.front().second] = 1;
		int flag = 0;
		while (!sang.empty())
		{
			auto cur = sang.front();
			sang.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx > h || ny < 0 || ny > w)
					continue;
				if (board[nx][ny] == '#' || dist[cur.first][cur.second] + 1 > abs(dist[nx][ny]))
					continue;
				sang.push({nx, ny});
				dist[nx][ny] = dist[cur.first][cur.second] + 1;
			}
		}

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cout << dist[i][j] << "\t";
			}
			cout << "\n";
		}
		int ans = INT_MAX;
		for (int i = 0; i < w; i++)
		{
			if (dist[0][i] > 0)
				ans = min(ans, dist[0][i]);
		}

		for (int i = 0; i < w; i++)
		{
			if (dist[h - 1][i] > 0)
				ans = min(ans, dist[h - 1][i]);
		}

		for (int i = 0; i < h; i++)
		{
			if (dist[i][0] > 0)
				ans = min(ans, dist[i][0]);
		}

		for (int i = 0; i < h; i++)
		{
			if (dist[i][w - 1] > 0)
				ans = min(ans, dist[i][w - 1]);
		}
		if (ans <= 0 || ans == INT_MAX)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << "\n";
	}

	return 0;
}