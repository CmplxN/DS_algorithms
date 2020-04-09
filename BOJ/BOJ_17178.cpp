#include <bits/stdc++.h>
using namespace std;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n;
	string s;
	priority_queue<pair<char, int>,vector<pair<char, int>>,greater<pair<char, int>>> pq;
	vector<pair<char, int>> v;
	stack<pair<char, int>> stk;
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 5; ++j) {
			cin >> s;
			pq.push({s[0], atoi(s.c_str() + 2)});
			v.emplace_back(s[0], atoi(s.c_str() + 2));
		}
	int vi=0;
	while(!pq.empty()){
		pair<char, int> now = pq.top();
		if(!stk.empty()&&stk.top()==now){
			pq.pop();
			stk.pop();
			continue;
		}
		while(vi<v.size()&&now!=v[vi]){
			stk.push(v[vi++]);
		}
		if(vi==v.size()&&stk.top()!=now){
			cout<<"BAD";
			return 0;
		}
		pq.pop();
		vi++;
	}
	cout<<"GOOD";
	return 0;
}
