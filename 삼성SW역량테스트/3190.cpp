#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, k, l;
// 2 -> 사과, 1 -> 뱀
int board[101][101];
queue<pair<int, char>> dir;

char dir_arr[4] = {'E', 'S', 'W', 'N'};
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

pair<int, int> get_dir(pair<int, int> head, char cur_dir) {
  if (cur_dir == 'E') {
    head.first += dx[0];
    head.second += dy[0];
  } else if (cur_dir == 'W') {
    head.first += dx[1];
    head.second += dy[1];
  } else if (cur_dir == 'S') {
    head.first += dx[2];
    head.second += dy[2];
  } else {
    head.first += dx[3];
    head.second += dy[3];
  }
  return head;
}

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  cin >> k;
  int x, y;
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    board[x][y] = 2;
  }
  cin >> l;
  int d;
  char di;
  for (int i = 0; i < l; i++) {
    cin >> d >> di;
    dir.push({d, di});
  }
  deque<pair<int, int>> head;
  int ans = 0;
  char cur_dir = 'E';
  head.push_back({1, 1});
  map<char, int> M;
  M['E'] = 0;
  M['S'] = 1;
  M['W'] = 2;
  M['N'] = 3;
  while (true) {
    // cout << cur_dir << " ";
    ans++;
    auto cur = get_dir(head.front(), cur_dir);
    // cout << cur.first << " " << cur.second << "\n";
    if (cur.first < 1 || cur.first > n || cur.second < 1 || cur.second > n)
      break;
    bool flag = true;
    for (auto a : head) {
      if (a.first == cur.first && a.second == cur.second) {
        flag = false;
        break;
      }
    }
    if (!flag)
      break;
    head.push_front(cur);
    if (board[cur.first][cur.second] == 2) {
      board[cur.first][cur.second] = 0;
    } else {
      // auto prev = head[1];
      // // head[0] = get_dir(head[0], cur_dir);
      // for (int i = ; i < head.size(); i++) {
      //   auto next = head[i];
      //   head[i] = prev;
      //   prev = next;
      // }
      head.pop_back();
    }
    if (!dir.empty() && ans == dir.front().first) {
      int t;
      if (dir.front().second == 'D') {
        t = M[cur_dir] + 1;
        if (t >= 4)
          t = 0;
        cur_dir = dir_arr[t];
      } else {
        t = M[cur_dir] - 1;
        if (t <= -1)
          t = 3;
        cur_dir = dir_arr[t];
      }
      cur_dir = dir_arr[t];
      dir.pop();
    }
    // for (auto a : head) {
    //   cout << "(" << a.first << "," << a.second << ") ";
    // }
    // cout << "\n";
  }
  cout << ans;
  return 0;
}