#include <bits/stdc++.h>
using namespace std;
int l,nums[11],ops[11],input[4];
int maxi = -2147483648;
int mini = 2147483647;
void solve() {
	int result = nums[0];
	vector<int> intermediaryN;
	vector<int> intermediaryO;
	for (int i = 0; i < l - 1; ++i) {
		if (ops[i] > 1) {
			if (ops[i] == 2) {
				result *= nums[i + 1];
			} else {
				result /= nums[i + 1];
			}
		} else {
			intermediaryN.push_back(result);
			intermediaryO.push_back(ops[i]);
			result = nums[i + 1];
		}
	}
	intermediaryN.push_back(result);
	result = intermediaryN[0];
	for(int i=0;i<intermediaryO.size();++i){
		if(intermediaryO[i]==0){
			result += intermediaryN[i+1];
		}else {
			result -= intermediaryN[i+1];
		}
	}
	maxi = max(maxi,result);
	mini = min(mini,result);
}
void select(int d) {
	if (d == l - 1) {
		solve();
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (input[i] < 1) continue;
		input[i]--;
		ops[d] = i;
		select(d + 1);
		input[i]++;
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> l;
	for (int i = 0; i < l; ++i) cin >> nums[i];
	for (int &i : input) cin >> i;
	select(0);
	cout << maxi << '\n' << mini;
	return 0;
}
