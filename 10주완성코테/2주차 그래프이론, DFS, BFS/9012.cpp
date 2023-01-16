#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int t;
string s;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> t;
  while (t--) {
    cin >> s;
    stack<char> st;
    for (auto c : s) {
      if (st.empty())
        st.push(c);
      else {
        if (st.top() == '(' && c == ')')
          st.pop();
        else
          st.push(c);
      }
    }
    if (st.empty())
      cout << "YES\n";
    else
      cout << "NO\n";
  }

  return 0;
}