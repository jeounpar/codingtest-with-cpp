#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  int t;
  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 0; i < n * n; i++) {
    cin >> t;
    pq.push(t);
    if (pq.size() > n)
      pq.pop();
  }
  cout << pq.top();
  return 0;
}