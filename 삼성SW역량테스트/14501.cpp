#include <iostream>
using namespace std;

int t[21];
int p[21];
int n;
int ans = 0;
void solve(int day, int sum) {
    if (day == n+1) {
        if (ans < sum) ans = sum;
        return;
    }
    if (day > n+1) {
        return;
    }
    solve(day+1, sum);
    solve(day+t[day], sum+p[day]);
}
int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        cin >> t[i] >> p[i];
    }
    solve(1, 0);
    cout << ans << '\n';
    return 0;
}