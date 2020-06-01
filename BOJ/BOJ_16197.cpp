#include <bits/stdc++.h>
using namespace std;
int N,M,x,xx,yy,y=-1,ans=-1;
string field[20];
int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};
set<pair<pair<int,int>,pair<int,int>>> st;
void dfs(int x1, int y1, int x2, int y2, int dep) {
	if (dep == 10) return;
	st.insert(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
	for (int i = 0; i < 4; ++i) {
		int nx1 = x1 + dx[i];
		int nx2 = x2 + dx[i];
		int ny1 = y1 + dy[i];
		int ny2 = y2 + dy[i];
		if ((nx1 < 0 || ny1 < 0 || nx1 >= M || ny1 >= N) && (nx2 < 0 || ny2 < 0 || nx2 >= M || ny2 >= N)) continue;
		if (nx1 < 0 || ny1 < 0 || nx2 < 0 || ny2 < 0 || nx1 >= M || ny1 >= N || nx2 >= M || ny2 >= N) {
			if (ans == -1) ans = dep + 1;
			else ans = min(ans, dep + 1);
			continue;
		}
		if (field[ny1][nx1] == '#') {
			nx1 = x1;
			ny1 = y1;
		}
		if (field[ny2][nx2] == '#') {
			nx2 = x2;
			ny2 = y2;
		}
		if (st.find(make_pair(make_pair(nx1, ny1), make_pair(nx2, ny2))) != st.end()) continue;
		dfs(nx1, ny1, nx2, ny2, dep + 1);
	}
	st.erase(make_pair(make_pair(x1, y1), make_pair(x2, y2)));
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> field[i];
	for (int i = 0; i < N; ++i)
		for (int j = 0; j < M; ++j) {
			if (field[i][j] == 'o' && y == -1) {
				x = j;
				y = i;
			} else if (field[i][j] == 'o' && y != -1) {
				xx = j;
				yy = i;
			}
		}
	dfs(x, y, xx, yy, 0);
	cout << ans;
	return 0;
}
