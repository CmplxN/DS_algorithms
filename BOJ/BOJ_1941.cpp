#include <bits/stdc++.h>
#define SIZE 5
#define MAX 7
using namespace std;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int ans;
string field[SIZE];
vector<pair<int,int>> selected;
vector<pair<int,int>> v;
bool connected(){
	set<pair<int,int>> st;
	set<pair<int,int>> ust;
	queue<pair<int,int>> q;
	int cnt = 1;
	for(auto it : selected) st.insert(it);
	q.push(selected[0]);
	ust.insert(selected[0]);
	while(!q.empty()){
		auto now = q.front();
		q.pop();
		for(int i=0;i<4;++i){
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if(st.find({nx,ny})==st.end() || ust.find({nx,ny})!=ust.end()) continue;
			ust.insert({nx,ny});
			q.push({nx,ny});
			cnt++;
		}
	}
	return cnt==7;
}
bool countS(){
	int cnt = 0;
	for(auto it : selected) if(field[it.second][it.first]=='S') cnt++;
	return cnt>=4;
}
void select(int dep){
	if(selected.size()==MAX){
		if(countS()){
			if(connected()) ans++;
		}
		return;
	}
	for(int i=dep;i<SIZE*SIZE;++i){
		if(selected.size()<MAX) {
			selected.emplace_back(i%5,i/5);
			select(i + 1 );
			selected.pop_back();
		}
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	cin>>field[0]>>field[1]>>field[2]>>field[3]>>field[4];
	for(int i=0;i<SIZE;++i) for(int j=0;j<SIZE;++j) if(field[i][j]=='S') v.emplace_back(j,i);
	select(0);
	cout<<ans;
	return 0;
}
