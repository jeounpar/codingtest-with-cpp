#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[26];
char mid;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  string s;
  cin >> s;
  for (auto c : s)
    arr[c - 'A'] += 1;
  string ans = "";
  int flag = 0;
  for (int i = 25; i >= 0; i--) {
    if (arr[i] % 2 != 0) {
      mid = char(i + 'A');
      arr[i]--;
      flag++;
      if (flag >= 2)
        break;
    }
    for (int j = 0; j < arr[i]; j += 2) {
      ans = char(i + 'A') + ans;
      ans += char(i + 'A');
    }
  }
  if (mid)
    ans.insert(ans.begin() + ans.size() / 2, mid);
  if (flag >= 2)
    cout << "I\'m Sorry Hansoo";
  else
    cout << ans;
  return 0;
}