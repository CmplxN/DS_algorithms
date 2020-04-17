#include <bits/stdc++.h>
#define SIZE 1000
using namespace std;
int n,m,field[SIZE][SIZE],cnt,ans;
map<int,int> mp;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
int dfs(int x, int y, int flag) {
	int rtn = 1;
	field[y][x] = flag;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || nx < 0 || nx >= m || ny >= n || field[ny][nx] != 1) continue;
		rtn += dfs(nx, ny, flag);
	}
	return rtn;
}
int search(int x, int y) {
	set<int> st;
	int rtn = 1;
	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (ny < 0 || nx < 0 || nx >= m || ny >= n || field[ny][nx] == 0) continue;
		if (st.find(field[ny][nx]) == st.end()) {
			rtn += mp[field[ny][nx]];
			st.insert(field[ny][nx]);
		}
	}
	return rtn;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> field[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (field[i][j] == 1) {
				mp[cnt + 2] = dfs(j, i, cnt + 2);
				ans = max(ans, mp[cnt + 2]);
				cnt++;
			}
		}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			if (field[i][j] == 0) {
				ans = max(ans, search(j, i));
			}
		}
	cout << ans;
	return 0;
}
