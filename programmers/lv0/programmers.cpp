#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<int> solution(vector<int> progresses, vector<int> speeds)
{
	vector<int> answer;
	vector<int> vc;
	for (int i = 0; i < speeds.size(); i++)
	{
		if ((100 - progresses[i]) % speeds[i] != 0)
			vc.push_back((100 - progresses[i]) / speeds[i] + 1);
		else
			vc.push_back((100 - progresses[i]) / speeds[i]);
	}
	int task = vc[0];
	int day = 0;

	for (int i = 0; i < vc.size(); i++)
	{
		if (vc[i] > task)
		{
			task = vc[i];
			answer.push_back(day);
			day = 0;
		}
		day++;
	}
	answer.push_back(day);
	return answer;
}
