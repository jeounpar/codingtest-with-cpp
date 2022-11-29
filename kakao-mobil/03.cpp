#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<string> split(string input, string delimiter)
{
	vector<string> ret;
	long long pos = 0;
	string token = "";
	while ((pos = input.find(delimiter)) != string::npos)
	{
		token = input.substr(0, pos);
		ret.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

vector<int> solution(string s, vector<string> times)
{
	vector<int> answer;
	vector<string> start = split(s, ":");
	vector<int> start_time;
	for (auto str : start)
		start_time.push_back(stoi(str));
	// 년:0 월:1 일:2 시:3 분:4 초:5
	int start_total_day = (start_time[0] - 1) * 360 + (start_time[1] - 1) * 30 + start_time[2];
	int flag = 1;
	vector<int> test;
	for (auto str : times)
	{
		// 일:0 시:1 분:2 초:3
		vector<string> time_vc = split(str, ":");
		vector<int> time_vc_int;
		for (auto a : time_vc)
			time_vc_int.push_back(stoi(a));
		// 초 단위 계산
		int carry = 0;
		if (start_time[5] + time_vc_int[3] > 59)
			carry = 1;
		start_time[5] = (start_time[5] + time_vc_int[3]) % 60;
		start_time[4] += carry;
		carry = 0;

		// 분 단위 계산
		if (start_time[4] + time_vc_int[2] > 59)
			carry = 1;
		start_time[4] = (start_time[4] + time_vc_int[2]) % 60;
		start_time[3] += carry;
		carry = 0;

		// 시간 단위 계산
		if (start_time[3] + time_vc_int[1] > 23)
			carry = 1;
		start_time[3] = (start_time[3] + time_vc_int[1]) % 24;
		start_time[2] += carry;
		carry = 0;

		// 일 단위 계산
		if (start_time[2] + time_vc_int[0] > 30)
			carry = 1;
		start_time[2] = (start_time[2] + time_vc_int[0]) % 31;
		if (start_time[2] == 0)
			start_time[2] += 1;
		start_time[1] += carry;
		carry = 0;

		// 월
		if (start_time[1] > 12)
			carry = 1;
		start_time[1] = start_time[1] % 13;
		if (start_time[1] == 0)
			start_time[1] += 1;
		start_time[0] += carry;
		carry = 0;

		int today = (start_time[0] - 1) * 360 + (start_time[1] - 1) * 30 + start_time[2];
		if (test.empty())
			test.push_back(today);
		else
		{
			test.push_back(today);
			if (test[test.size() - 2] == today || (test[test.size() - 2] + 1) == today)
				;
			else
				flag = 0;
		}
	}
	int end_total_day = (start_time[0] - 1) * 360 + (start_time[1] - 1) * 30 + start_time[2];
	answer.push_back(flag);
	answer.push_back(end_total_day - start_total_day + 1);
	return answer;
}