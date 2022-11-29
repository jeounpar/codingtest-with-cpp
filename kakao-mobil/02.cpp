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

int solution(vector<string> id_list, int k)
{
	int answer = 0;
	unordered_map<string, int> M;
	for (auto str : id_list)
	{
		vector<string> token = split(str, " ");
		sort(token.begin(), token.end());
		token.erase(unique(token.begin(), token.end()), token.end());
		for (auto tok : token)
		{
			if (M.find(tok) == M.end())
				M[tok] = 1;
			else
				M[tok] += 1;
		}
	}
	for (auto a : M)
	{
		if (a.second >= k)
			answer += k;
		else
			answer += a.second;
	}
	return answer;
}