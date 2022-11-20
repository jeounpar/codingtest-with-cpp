#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> arr(n);
	vector<bool> chk(100002);
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	long long ans = 0;
	chk[arr[0]] = 1;
	int en = 0;
	for (int st = 0; st < n; st++)
	{
		while (en < n - 1 && !chk[arr[en + 1]])
		{
			cout << arr[en + 1] << "\n";
			en++;
			chk[arr[en]] = 1;
		}
		for (int i = 0; i < n; i++)
			cout << chk[i] << " ";
		cout << "\n";
		ans += (en - st + 1);
		chk[arr[st]] = 0;
	}
	cout << ans;
}

// #include <bits/stdc++.h>

// using namespace std;
// typedef long long ll;

// int n;
// int a[100001];
// int main(void)
// {
// 	ios_base::sync_with_stdio(0);
// 	cin.tie(0);
// 	cin >> n;
// 	for (int i = 0; i < n; i++)
// 		cin >> a[i];
// 	int ans = n;
// 	int len = 2;
// 	while (len <= n)
// 	{
// 		for (int st = 0; st < n; st++)
// 		{
// 			vector<int> vc;
// 			// cout << st + len - 1 << " ";
// 			if (st + len - 1 >= n)
// 				continue;
// 			for (int ed = st; ed <= st + len - 1; ed++)
// 			{
// 				// cout << a[ed] << " ";
// 				if (vc.size() == 0)
// 					vc.push_back(a[ed]);
// 				else
// 				{
// 					if (find(vc.begin(), vc.end(), a[ed]) == vc.end())
// 						vc.push_back(a[ed]);
// 					else
// 						break;
// 				}
// 			}
// 			// for (auto x : vc)
// 			// 	cout << x << " ";
// 			// cout << "size = " << vc.size() << "\n";
// 			if (vc.size() == len)
// 				ans++;
// 		}
// 		// cout << "len = " << len << "\n";
// 		len++;
// 	}
// 	cout << ans;
// 	return 0;
// }