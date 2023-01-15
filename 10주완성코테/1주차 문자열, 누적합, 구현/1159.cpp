#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int arr[26];
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);
  string answer = "";
  int n;
  cin >> n;
  string s;
  while (n--) {
    cin >> s;
    arr[s[0] - 'a'] += 1;
  }
  for (int i = 0; i < 26; i++) {
    if (arr[i] >= 5)
      answer += i + 'a';
  }
  if (answer.size() == 0)
    cout << "PREDAJA";
  else
    cout << answer;
  return 0;
}