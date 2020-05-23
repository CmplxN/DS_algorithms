#include <bits/stdc++.h>
using namespace std;
int dp[10001],input[22];
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> input[i];
		int tar;
		cin >> tar;
		memset(dp, 0, sizeof(dp));
		dp[0] = 1;
		for (int i = 1; i <= n; ++i)
			for (int j = input[i - 1]; j <= tar; ++j)
				dp[j] += dp[j - input[i - 1]];
		cout << dp[tar] << '\n';
	}
	return 0;
}
