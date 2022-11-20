#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, m;
int board[301][301];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int ans = 0;
queue<pair<int, int>> Q;
int solve()
{
	queue<pair<int, int>> chk;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx > n || ny < 0 || ny > m)
				continue;
			if (board[nx][ny] == 0)
				continue;
			else
				board[nx][ny] -= 1;
		}
	}
	int cnt = 0;
	int cnt2 = 0;
	int flag = 0;
	bool ok[301][301] = {
			0,
	};
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				Q.push({i, j});
				cnt++;
			}
			else if (flag == 0 && board[i][j] != 0)
			{
				flag = 1;
				cnt2++;
				// cout << "here\n";
				ok[i][j] = true;
				chk.push({i, j});
			}
		}
	}
	// cout << "cnt = " << cnt << "\n";
	if (cnt == n * m)
		return -1;
	// cout << chk.front().first << " " << chk.front().second << "\n";
	while (!chk.empty())
	{
		auto cur = chk.front();
		chk.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			// cout << "board = " << board[nx][ny] << " ok = " << ok[nx][ny] << "\n";
			if (nx < 0 || nx > n || ny < 0 || ny > m)
				continue;
			if (board[nx][ny] == 0 || ok[nx][ny])
				continue;
			ok[nx][ny] = true;
			cnt2++;
			chk.push({nx, ny});
			// cout << nx << " " << ny << "\n";
		}
	}
	// cout << "cnt, cnt2 => " << cnt << " " << cnt2 << "\n";
	return cnt + cnt2;
}

void print_board()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int flag = 0;
	queue<pair<int, int>> test;
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 0)
			{
				Q.push({i, j});
				cnt++;
			}
			else
			{
				if (flag == 0)
				{
					test.push({i, j});
					flag++;
				}
				else
					continue;
			}
		}
	}
	bool ok[301][301] = {
			0,
	};
	int cnt2 = 0;
	while (!test.empty())
	{
		auto cur = test.front();
		test.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			// cout << "board = " << board[nx][ny] << " ok = " << ok[nx][ny] << "\n";
			if (nx < 0 || nx > n || ny < 0 || ny > m)
				continue;
			if (board[nx][ny] == 0 || ok[nx][ny])
				continue;
			ok[nx][ny] = true;
			cnt2++;
			test.push({nx, ny});
			// cout << nx << " " << ny << "\n";
		}
	}
	if (cnt == n * m)
	{
		cout << 0;
		return 0;
	}
	if (cnt + cnt2 != n * m)
	{
		// cout << "\n";
		// cout << cnt << " " << cnt2 << "\n";
		// print_board();
		cout << 0;
		return 0;
	}
	// ans++;
	if (cnt2)
		while (true)
		{
			int rst = solve();
			ans++;
			// cout << "\n";
			// print_board();
			// cout << "rst = " << rst << "\n";
			if (rst == -1)
			{
				cout << 0;
				return 0;
			}
			if (rst != n * m)
			{
				break;
			}
		}
	cout << ans;
	return 0;
}