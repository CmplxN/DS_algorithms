#include <bits/stdc++.h>
using namespace std;
int tPow[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int exchange(int n1, int n2, int original){
	int temp1 = original%tPow[n1]/tPow[n1-1]*tPow[n2-1];
	int temp2 = original%tPow[n2]/tPow[n2-1]*tPow[n1-1];
	original -= original%tPow[n1]/tPow[n1-1]*tPow[n1-1];
	original -= original%tPow[n2]/tPow[n2-1]*tPow[n2-1];
	original += temp1;
	original += temp2;
	return original;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int puz = 0, input, loc = 0;
	map<int, int> ans;
	queue<pair<int, int>> q;
	for (int i = 0; i < 9; ++i) {
		cin >> input;
		if (input == 0) {
			loc = 9 - i;
			input = 9;
		}
		puz = puz * 10 + input;
	}
	q.push({puz, loc});
	ans[puz] = 0;
	while (!q.empty()) {
		pair<int, int> now = q.front();
		if (now.first == 123456789) {
			cout << ans[now.first];
			return 0;
		}
		q.pop();
		if(now.second%3!=0){ // 왼쪽 이동 가능
			int next = exchange(now.second,now.second+1,now.first);
			if(ans.find(next)==ans.end()) {
				ans[next] = ans[now.first] + 1;
				q.push({next,now.second+1});
			}
		}
		if(now.second%3!=1){ // 오른쪽 이동 가능
			int next = exchange(now.second,now.second-1,now.first);
			if(ans.find(next)==ans.end()) {
				ans[next] = ans[now.first] + 1;
				q.push({next,now.second-1});
			}
		}
		if((now.second-1)/3!=2) { // 위쪽 이동 가능
			int next = exchange(now.second,now.second+3,now.first);
			if(ans.find(next)==ans.end()) {
				ans[next] = ans[now.first] + 1;
				q.push({next,now.second+3});
			}
		}
		if((now.second-1)/3!=0){ // 아래쪽 이동 가능
			int next = exchange(now.second,now.second-3,now.first);
			if(ans.find(next)==ans.end()) {
				ans[next] = ans[now.first] + 1;
				q.push({next,now.second-3});
			}
		}
	}
	cout << -1;
	return 0;
}
