#include <bits/stdc++.h>

using namespace std;

char board[1001][1001];
int fire[1001][1001];
int sang[1001][1001];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> s_start;
int w, h;

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--)
	{
		cin >> w >> h;
		queue<pair<int, int>> Qf;
		queue<pair<int, int>> Qs;
		for (int i = 0; i < h; i++)
		{
			string s;
			cin >> s;
			for (int j = 0; j < w; j++)
			{
				if (s[j] == '#')
				{
					fire[i][j] = -1;
					sang[i][j] = -1;
				}
				else if (s[j] == '*')
				{
					Qf.push({i, j});
					fire[i][j] = 1;
				}
				else if (s[j] == '@')
				{
					Qs.push({i, j});
					sang[i][j] = 1;
				}
			}
		}
		while (!Qf.empty())
		{
			auto cur = Qf.front();
			Qf.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (fire[nx][ny] == -1 || fire[nx][ny] != 0)
					continue;
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
					continue;
				fire[nx][ny] = fire[cur.first][cur.second] + 1;
				Qf.push({nx, ny});
			}
		}
		bool is_valid = false;
		while (!Qs.empty() && (!is_valid))
		{
			auto cur = Qs.front();
			Qs.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || nx >= h || ny < 0 || ny >= w)
				{
					is_valid = true;
					cout << sang[cur.first][cur.second] << "\n";
					break;
				}
				if (board[nx][ny] == -1)
					continue;
				if (sang[nx][ny] == -1 || sang[nx][ny] != 0)
					continue;
				if (fire[nx][ny] != 0 && sang[cur.first][cur.second] + 1 >= fire[nx][ny])
					continue;
				sang[nx][ny] = sang[cur.first][cur.second] + 1;
				Qs.push({nx, ny});
			}
		}
		// for (int i = 0; i < h; i++)
		// {
		// 	for (int j = 0; j < w; j++)
		// 		cout << sang[i][j] << " ";
		// 	cout << "\n";
		// }
		if (!is_valid)
			cout << "IMPOSSIBLE\n";
	}
	return 0;
}