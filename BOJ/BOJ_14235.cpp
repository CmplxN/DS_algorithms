#include <bits/stdc++.h>
using namespace std;
int t,input,val;
priority_queue<int> pq;
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>input;
		if(input == 0) {
			if(!pq.empty()){
				cout<<pq.top()<<'\n';
				pq.pop();
			}
			else cout<<-1<<'\n';
		}
		while(input--){
			cin>>val;
			pq.push(val);
		}
	}
	return 0;
}
