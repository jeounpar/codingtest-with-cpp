#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
  // ios_base::sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(NULL);

  string s;
  while (true) {
    getline(cin, s);
    if (s == ".")
      break;
    stack<char> st;
    for (auto c : s) {
      if (c == '(' || c == ')' || c == '[' || c == ']') {
        if (st.empty())
          st.push(c);
        else {
          if (st.top() == '(' && c == ')')
            st.pop();
          else if (st.top() == '[' && c == ']')
            st.pop();
          else
            st.push(c);
        }
      }
    }
    if (st.empty())
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}