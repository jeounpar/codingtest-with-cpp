#include <bits/stdc++.h>

using namespace std;

char arr[101][101];
char color[3] = {'R', 'G', 'B'};
bool ok[101][101];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int n;

void solve(int x, int y, char c)
{
	queue<pair<int, int>> q;
	q.push({x, y});
	while (!q.empty())
	{
		auto cur = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.first + dx[i];
			int ny = cur.second + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;
			if (ok[nx][ny] || arr[nx][ny] != c)
				continue;
			ok[nx][ny] = true;
			q.push({nx, ny});
		}
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
			arr[i][j] = s[j];
	}
	int ans = 0;
	for (auto c : color)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ok[i][j] || arr[i][j] != c)
					continue;
				solve(i, j, c);
				ans++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		fill(ok[i], ok[i] + n, false);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 'G')
			{
				arr[i][j] = 'R';
				continue;
			}
		}
	}
	int ans_2 = 0;
	for (auto c : color)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (ok[i][j] || arr[i][j] != c)
					continue;
				solve(i, j, c);
				ans_2++;
			}
		}
	}
	cout << ans << " " << ans_2 << "\n";
	return 0;
}