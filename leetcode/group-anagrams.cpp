#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

bool cmp(string a, string b) { return a.size() < b.size(); }

vector<vector<string>> groupAnagrams(vector<string> &strs) {
  vector<vector<string>> ans;
  unordered_map<string, vector<string>> M;
  for (auto str : strs) {
    string tmp = str;
    sort(tmp.begin(), tmp.end());
    M[tmp].push_back(str);
  }
  for (auto a : M)
    ans.push_back(a.second);
  return ans;
}