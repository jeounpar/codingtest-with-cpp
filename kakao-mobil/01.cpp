#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int solution(vector<vector<int>> flowers)
{
	int answer = 0;
	bool year[366] = {
			0,
	};
	for (int i = 1; i <= 365; i++)
		year[i] = false;
	for (auto a : flowers)
	{
		for (int i = a[0]; i < a[1]; i++)
			year[i] = true;
	}
	for (int i = 1; i <= 365; i++)
	{
		if (year[i])
			answer++;
	}
	return answer;
}