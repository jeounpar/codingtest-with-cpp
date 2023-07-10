#include<bits/stdc++.h>

using namespace std;

int ans = INT_MAX;
int n, m;

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<string> board;

typedef struct {
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt;
} INFO;

bool visited[21][21][21][21];

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	string s;
	queue<INFO> Q;
	int t = 1;
	INFO info;
	for (int i = 0; i < n; i++) {
		cin >> s;
		board.push_back(s);
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 'o' && t == 1) {
				info.x1 = i;
				info.y1 = j;
				t++;
			}
			else if (board[i][j] == 'o' && t == 2) {
				info.x2 = i;
				info.y2 = j;
			}
		}
	}
	visited[info.x1][info.y1][info.x2][info.y2] = true;
	info.cnt = 0;
	Q.push(info);
	while (!Q.empty()) {
		auto cur = Q.front(); Q.pop();
		// cout << cur.x1 << " " << cur.y1 << " " << cur.x2 << " " << cur.y2 << "\n";
		if (cur.cnt >= 10) {
			break;
		}
		for (int i = 0; i < 4; i++) {
			int nx1 = cur.x1 + dx[i];
			int ny1 = cur.y1 + dy[i];
			int nx2 = cur.x2 + dx[i];
			int ny2 = cur.y2 + dy[i];
			int fall = 0;
			if (nx1 < 0 || nx1 >= n || ny1 < 0 || ny1 >= m)
				fall++;
			if(nx2 < 0 || nx2 >= n || ny2 < 0 || ny2 >= m)
				fall++;
			if (fall == 2)
				continue;
			else if (fall == 1) {
				ans = min(ans, cur.cnt + 1);
			}
			else {
				if (board[nx1][ny1] == '#') {
					nx1 = cur.x1;
					ny1 = cur.y1;
				}
				if (board[nx2][ny2] == '#') {
					nx2 = cur.x2;
					ny2 = cur.y2;
				}
				if (visited[nx1][ny1][nx2][ny2])
					continue;
				visited[nx1][ny1][nx2][ny2] = true;
				INFO newInfo;
				newInfo.x1 = nx1;
				newInfo.x2 = nx2;
				newInfo.y1 = ny1;
				newInfo.y2 = ny2;
				newInfo.cnt = cur.cnt + 1;
				Q.push(newInfo);
			}
		}
	}
	if (ans == INT_MAX)
		ans = -1;
	cout << ans << "\n";
	return 0;
}