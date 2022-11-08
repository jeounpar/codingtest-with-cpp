#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int board[11][11];
bool ok[11][11];
vector<int> area;

void solve(int x, int y)
{
	queue<pair<int, int>> Q;
	Q.push({x, y});
	ok[x][y] = true;
	int area_cnt = 0;
	while (!Q.empty())
	{
		auto cur = Q.front();
		Q.pop();
		area_cnt++;
		for (int i = 0; i <= 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 1 || nx > n || ny < 1 || ny > n)
				continue;
			if (board[nx][ny] != 1 || ok[nx][ny])
				continue;
			ok[nx][ny] = true;
			Q.push({nx, ny});
		}
	}
	if (area_cnt > 0)
		area.push_back(area_cnt);
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> board[i][j];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] != 1 || ok[i][j])
				continue;
			solve(i, j);
			cnt++;
		}
	}
	sort(area.begin(), area.end());
	cout << cnt << "\n";
	for (int i = 0; i < area.size(); i++)
	{
		if (i + 1 == area.size())
		{
			cout << area[i] << "\n";
			break;
		}
		cout << area[i] << " ";
	}
	return 0;
}