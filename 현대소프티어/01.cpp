#include <bits/stdc++.h>
// 코드 참고 https://cocoon1787.tistory.com/279
using namespace std;
typedef long long ll;

int n;
char board[65][65];

void solve(int x, int y, int max_size)
{
	for (int i = x; i < x + max_size; i++)
		for (int j = y; j < y + max_size; j++)
		{
			if (board[i][j] != board[x][y])
			{
				cout << "(";
				solve(x, y, max_size / 2);
				solve(x, y + max_size / 2, max_size / 2);
				solve(x + max_size / 2, y, max_size / 2);
				solve(x + max_size / 2, y + max_size / 2, max_size / 2);
				cout << ")";
				return;
			}
		}
	cout << board[x][y];
}

int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	solve(0, 0, n);
	return 0;
}