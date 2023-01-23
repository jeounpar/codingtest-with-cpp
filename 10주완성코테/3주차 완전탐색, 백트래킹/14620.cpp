#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[12][12];
bool visited[12][12];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
  int idx = (n - 2) * (n - 2);
  for (int i = 1; i <= idx; i++) {
    /* code */
  }

  return 0;
}