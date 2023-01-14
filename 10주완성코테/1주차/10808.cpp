#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[26];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    arr[s[i] - 'a'] += 1;
  }
  for (int i = 0; i < 26; i++) {
    cout << arr[i] << " ";
  }

  return 0;
}