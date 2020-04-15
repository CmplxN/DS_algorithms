#include <bits/stdc++.h>
using namespace std;
set<int> st;
int input[5][5];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
void dfs(int x,int y,int n, int no){
	if(n==6){
		st.insert(no);
		return;
	}
	for(int i=0;i<4;++i){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=5||ny>=5) continue;
		dfs(nx,ny,n+1,10*no+input[ny][nx]);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	for(auto & i : input) for(int & j : i) cin>>j;
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j){
			dfs(j,i,0,0);
		}
	}
	cout<<st.size();
	return 0;
}
