#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

string a, b;
int main(void)
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> a;
	cin >> b;
	int min_inst = 0;
	int left = 0, right = 0;
	int b_size = b.length();

	vector<char> a_copy(a.begin(), a.end());
	vector<char> b_copy(b.begin(), b.end());

	for (int i = 0; i < b.length(); i++)
	{
		auto q = find(a_copy.begin(), a_copy.end(), b[i]);
		// cout << b_copy[i] << " ";
		if (q == a_copy.end())
			cout << -1 << "\n";
		// cout << "asd\n";
	}
	int cur = 0;
	int st = 0;
	while (st < b_size)
	{
		auto q = find(a_copy.begin(), a_copy.end(), b[st]);
		// cur = q - a_copy.begin();
		// st++;
		// cout << q - a_copy.begin();
		int left_cnt = 0;
		int tmp = cur;
		while (a_copy[tmp] != b[st])
		{
			// cout << "a\n";
			if (tmp - 1 < 0)
				tmp = a_copy.size() - 1;
			else
				tmp--;
			left_cnt++;
		}
		int right_cnt = 0;
		tmp = cur;
		while (a_copy[tmp] != b[st])
		{
			// cout << "b\n";
			if (tmp + 1 > a_copy.size() - 1)
				tmp = 0;
			else
				tmp++;
			right_cnt++;
		}
		cur = q - a_copy.begin();
		if (left_cnt < right_cnt)
		{
			min_inst += left_cnt;
			left += left_cnt;
		}
		else
		{
			min_inst += right_cnt;
			right += right_cnt;
		}
		min_inst++;
		// cout << min_inst << " " << left_cnt << " " << right_cnt << "\n";
		st++;
		// break;
	}
	cout << min_inst << " " << right << " " << left;
	return 0;
}