#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<vector<int>> threeSum(vector<int> &nums) {
  set<vector<int>> answer;
  sort(nums.begin(), nums.end());
  for (int i = 0; i < nums.size() - 2; i++) {
    int j = i + 1;
    int k = nums.size() - 1;
    while (j < k) {
      int sum = nums[i] + nums[j] + nums[k];
      if (sum == 0) {
        answer.insert({nums[i], nums[j], nums[k]});
        j++;
        k--;
      } else if (sum < 0)
        j++;
      else if (sum > 0)
        k--;
    }
  }
  vector<vector<int>> ans;
  ans.assign(answer.begin(), answer.end());
  return ans;
}