#include <bits/stdc++.h>

using namespace std;

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