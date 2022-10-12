#include <bits/stdc++.h>

using namespace std;
char board[9][9];
vector<int> vc;
vector<int> cctv;
vector<pair<int, int>> gps;
int max_cctv = 0;
int n, m;
int ans = 999;
bool ok[9];

void make_flow(int k)
{
	if (k == max_cctv)
	{
		char tmp[9][9];
		copy(&board[0][0], &board[0][0] + 81, &tmp[0][0]);
		// 1 - 동
		// 2 - 서
		// 3 - 남
		// 4 - 북
		for (int i = 0; i < max_cctv; i++)
		{
			int x = gps[i].first;
			int y = gps[i].second;
			if (vc[i] == 1)
			{
				if (board[x][y] == '1')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
				}
				else if (board[x][y] == '2')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// west
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
				}
				else if (board[x][y] == '3')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '5')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// west
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '4')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// west
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
			}
			else if (vc[i] == 2)
			{
				if (board[x][y] == '1')
				{
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
				}
				else if (board[x][y] == '2')
				{
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '3')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '4')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
			}
			else if (vc[i] == 3)
			{
				// 남
				if (board[x][y] == '1')
				{
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '3')
				{
					// 서
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '4')
				{
					// east
					for (int j = y + 1; j < m; j++)
					{
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// west
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
			}
			else if (vc[i] == 4)
			{
				if (board[x][y] == '1')
				{
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '3')
				{
					// 서
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
				else if (board[x][y] == '4')
				{
					// west
					for (int j = y - 1; j >= 0; j--)
					{
						if (y - 1 < 0)
							break;
						if (tmp[x][j] == '#' || (tmp[x][j] >= '1' && tmp[x][j] <= '5'))
							continue;
						if (tmp[x][j] == '6')
							break;
						tmp[x][j] = '#';
					}
					// 남
					for (int j = x + 1; j < n; j++)
					{
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
					// 북
					for (int j = x - 1; j >= 0; j--)
					{
						if (x - 1 < 0)
							break;
						if (tmp[j][y] == '#' || (tmp[j][y] >= '1' && tmp[j][y] <= '5'))
							continue;
						if (tmp[j][y] == '6')
							break;
						tmp[j][y] = '#';
					}
				}
			}
		}
		int zero_cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (tmp[i][j] == '0')
					zero_cnt++;
			}
		}
		ans = min(ans, zero_cnt);
		return;
	}
	for (int i = 1; i <= cctv[k]; i++)
	{
		vc.push_back(i);
		make_flow(k + 1);
		vc.pop_back();
	}
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] >= '1' && board[i][j] <= '5')
			{
				max_cctv++;
				gps.push_back({i, j});
				if (board[i][j] == '1')
					cctv.push_back(4);
				else if (board[i][j] == '2')
					cctv.push_back(2);
				else if (board[i][j] == '3')
					cctv.push_back(4);
				else if (board[i][j] == '4')
					cctv.push_back(4);
				else if (board[i][j] == '5')
					cctv.push_back(1);
			}
		}
	}
	make_flow(0);
	cout << ans << "\n";
	return 0;
}