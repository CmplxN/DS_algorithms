#include <bits/stdc++.h>
#define MAX 99999999
using namespace std;
set<int> vv;
vector<int> v;
int candidate[1000001];
void dfs(int dep,int no){
	if(dep==6){
		if(no<=1000000) candidate[no]=min(dep,candidate[no]);
		return;
	}
	if(dep!=0) candidate[no]=min(dep,candidate[no]);
	for(auto it : v){
		dfs(dep+1,10*no+it);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int tar, m, input;
	cin >> tar >> m;
	for (int i = 0; i < m; ++i) {
		cin >> input;
		vv.insert(input);
	}
	for(int i=0;i<10;++i){
		if(vv.find(i)==vv.end())
			v.push_back(i);
	}
	for(int i=0;i<1000001;++i) candidate[i]=MAX;
	dfs(0, 0);
	candidate[100] = 0;
	int ans = MAX;
	for (int i = 0; i < 1000001; ++i) {
		if (candidate[i]>0||i==100) {
			int now = abs(tar - i) + candidate[i];
 			ans = min(ans, now);
		}
	}
	cout << ans;
	return 0;
}
