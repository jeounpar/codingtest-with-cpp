#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int n;
vector<int> vc;
int main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> n;
  int t;
  for (int i = 0; i < n; i++) {
    cin >> t;
    vc.push_back(t);
  }
  vector<int> tmp = vc;
  sort(tmp.begin(), tmp.end());
  // for (auto a : tmp)
  //   cout << a << " ";
  vector<int> comp;
  int tar = tmp[0];
  comp.push_back(tar);
  for (int i = 1; i < tmp.size(); i++) {
    if (tar == tmp[i])
      continue;
    tar = tmp[i];
    comp.push_back(tar);
  }
  // cout << "\n";
  // for (auto a : comp)
  //   cout << a << " ";
  // cout << "\n";
  for (auto a : vc) {
    cout << lower_bound(comp.begin(), comp.end(), a) - comp.begin() << " ";
  }
  return 0;
}