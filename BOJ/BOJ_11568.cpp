#include <bits/stdc++.h>
using namespace std;
int n,dp[1000],input,ans;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		auto pt = lower_bound(dp, dp + ans, input);
		*pt = input;
		if (pt == dp + ans) ans++;
	}
	cout << ans;
	return 0;
}
