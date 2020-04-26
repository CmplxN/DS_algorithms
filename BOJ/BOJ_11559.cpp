#include <bits/stdc++.h>
using namespace std;
string field[12];
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
bool visited[12][6];
void candidate(int x, int y, vector<pair<int,int>> &v) {
	queue<pair<int, int>> q;
	q.emplace(x, y);
	v.emplace_back(x, y);
	visited[y][x] = true;
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (nx < 0 || ny < 0 || nx >= 6 || ny >= 12 || visited[ny][nx] ||
			    field[ny][nx] != field[now.second][now.first] || field[ny][nx] == '.')
				continue;
			visited[ny][nx] = true;
			v.emplace_back(nx, ny);
			q.emplace(nx, ny);
		}
	}
}
void goDown(int x, int y){ // y 보다 위에있는애들 하나씩 y로
	int toHere = y;
	y--;
	while(y>=0){
		if(field[y][x]!='.'){
			swap(field[y][x],field[toHere][x]);
			toHere--;
		}
		y--;
	}
}
void apply(){
	for(int j=0;j<6;++j){
		for(int i=11;i>=0;--i){
			if(field[i][j]=='.'){
				goDown(j,i);
				break;
			}
		}
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int ans = 0;
	for (auto &i : field) cin >> i;
	bool allDot = true;
	for (const auto &it : field) for (auto c : it) if (c != '.') allDot = false;
	if (allDot) {
		cout << 0;
		return 0;
	}
	while (true) {
		bool checker = false;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 12; ++i)
			for (int j = 0; j < 6; ++j) {
				if (!visited[i][j]) {
					vector<pair<int, int>> v;
					candidate(j, i, v);
					if (v.size() < 4) continue;
					checker = true;
					for(auto it : v) field[it.second][it.first]='.';
				} else visited[i][j] = true;
			}
		if (!checker) break;
		ans++;
		apply();
	}
	cout << ans;
	return 0;
}
