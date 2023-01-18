#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
int arr[1000001];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n;
  int ans[1000001];
  stack<int> st;
  for (int i = 1; i <= n; i++) {
    ans[i] = -1;
    cin >> arr[i];
    while (!st.empty() && arr[st.top()] < arr[i]) {
      ans[st.top()] = arr[i];
      st.pop();
    }
    st.push(i);
  }

  for (int i = 1; i <= n; i++)
    cout << ans[i] << " ";
  return 0;
}