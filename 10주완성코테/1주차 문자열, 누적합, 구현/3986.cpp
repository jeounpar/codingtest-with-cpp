#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int cnt[2];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  string s;
  int ans = 0;
  while (n--) {
    cin >> s;
    stack<char> st;
    for (auto c : s) {
      if (st.empty())
        st.push(c);
      else {
        if (st.top() == c)
          st.pop();
        else
          st.push(c);
      }
    }
    if (st.empty())
      ans++;
  }
  cout << ans;
  return 0;
}