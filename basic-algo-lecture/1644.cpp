#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int prime[4000001];
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	prime[0] = 0;
	prime[1] = 0;
	for (int i = 2; i <= 4000000; i++)
		prime[i] = i;
	for (int i = 2; i <= sqrt(4000000); i++)
	{
		if (prime[i] == 0)
			continue;
		for (int j = i * i; j < 4000000; j += i)
			prime[j] = 0;
	}
	vector<int> vc(prime, prime + 4000000);
	sort(vc.begin(), vc.end());
	vc.erase(unique(vc.begin(), vc.end()), vc.end());
	int max_size = lower_bound(vc.begin(), vc.end(), n) - vc.begin() + 1;
	int ans = 0;
	for (int st = 1; st <= max_size; st++)
	{
		int sum = vc[st];
		int ed = st;
		while (ed < max_size && sum <= n)
		{
			ed++;
			if (sum == n)
			{
				ans++;
				break;
			}
			sum += vc[ed];
		}
		// if (ed == max_size)
		// 	break;
		// cout << "test = " << vc[st] << "\n";
	}
	cout << ans << "\n";
	return 0;
}