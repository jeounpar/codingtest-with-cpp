#include <bits/stdc++.h>

using namespace std;
string board[5];
int mask[25];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 0; i < 5; i++)
		cin >> board[i];
	fill(mask + 7, mask + 25, 1);
	int ans = 0;
	do
	{
		queue<pair<int, int>> q;
		bool isp7[5][5] = {};
		bool vis[5][5] = {};
		int dasom = 0, close = 0;
		for (int i = 0; i < 25; i++)
		{
			if (mask[i] == 0)
			{
				int x = i / 5;
				int y = i % 5;
				isp7[x][y] = true;
				if (q.empty())
				{
					q.push({x, y});
					vis[x][y] = true;
				}
			}
		}
		while (!q.empty())
		{
			int x, y;
			tie(x, y) = q.front();
			q.pop();
			close++;
			if (board[x][y] == 'S')
				dasom++;
			for (int k = 0; k < 4; k++)
			{
				int nx = x + dx[k];
				int ny = y + dy[k];
				if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || vis[nx][ny] || !isp7[nx][ny])
					continue;
				q.push({nx, ny});
				vis[nx][ny] = true;
			}
		}
		if (close >= 7 && dasom >= 4)
			ans++;
	} while (next_permutation(mask, mask + 25));
	cout << ans << "\n";
	return 0;
}
