#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solution(vector<int> &A) {
  int answer = 0;
  if (A.size() == 1)
    return 0;
  int n = A.size();
  A.push_back(A[0]);
  int a = 0, b = 0;
  for (int i = 0; i < n - 1; i++) {
    if (((A[i] % 2 == 0) && (A[i + 1] % 2 == 0)) ||
        ((A[i] % 2 != 0) && (A[i + 1] % 2 != 0))) {
      a++;
      i++;
    }
  }
  for (int i = 1; i < n; i++) {
    if (((A[i] % 2 == 0) && (A[i + 1] % 2 == 0)) ||
        ((A[i] % 2 != 0) && (A[i + 1] % 2 != 0))) {
      b++;
      i++;
    }
  }
  answer = max(a, b);
  return answer;
}
int a[200005];
int main() {
  for (int i = 1; i <= 50; i++)
    cout << (i & 1) << " ";
  // int n, a1 = 0, a2 = 0;
  // cin >> n;
  // for (int i = 1; i <= n; i++)
  //   cin >> a[i];
  // a[n + 1] = a[1];
  // for (int i = 1; i <= n - 1; i++) {
  //   if ((a[i] & 1) == (a[i + 1] & 1)) {
  //     a1++;
  //     i++;
  //   }
  // }
  // for (int i = 2; i <= n; i++) {
  //   if ((a[i] & 1) == (a[i + 1] & 1)) {
  //     a2++;
  //     i++;
  //   }
  // }
  // cout << max(a1, a2);
}