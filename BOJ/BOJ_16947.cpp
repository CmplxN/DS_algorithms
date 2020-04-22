#include <bits/stdc++.h>
using namespace std;
int N,a,b,save[3000],ans[3000];
vector<int> v[3000];
queue<int> q;
int dfs(int now, int prev) {
	if (save[now] == 1) return now;
	save[now] = 1;
	for (auto it : v[now]) {
		if (it == prev) continue;
		int rtn = dfs(it, now);
		if (rtn == -2) return -2;
		if (rtn >= 0) {
			save[now] = 2;
			if (rtn == now) return -2;
			else return rtn;
		}
	}
	return -1;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>N;
	for(int i=0;i<N;++i){
		cin>>a>>b;
		v[a-1].push_back(b-1);
		v[b-1].push_back(a-1);
	}
	dfs(0,-1);
	for(int i=0;i<N;++i){
		if (save[i]==2){
			q.push(i);
		} else ans[i] = -1;
	}
	int t = 0;
	while(true) {
		t++;
		int size = q.size();
		while (size--) {
			int now = q.front();
			q.pop();
			for (auto it : v[now]) {
				if (ans[it]>=0) continue;
				ans[it]=t;
				q.push(it);
			}
		}
		if(q.empty()) break;
	}
	for(int i=0;i<N;++i) cout<<ans[i]<<' ';
	return 0;
}
