#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n, l;
int arr[101][101];

int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(NULL);

  cin >> n >> l;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> arr[i][j];
	
  return 0;
}