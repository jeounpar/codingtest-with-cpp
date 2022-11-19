#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int n;
int a[51];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	
	return 0;
}