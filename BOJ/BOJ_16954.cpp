#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	int x,y,t;
}info;
int dx[] = {1,1,1,-1,-1,-1,0,0,0};
int dy[] = {1,0,-1,1,0,-1,1,-1,0};
bool visited[8][8][8];
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	string input[8];
	for (auto &i : input) cin >> i;
	queue<info> q;
	visited[0][7][0] = true;
	q.push({0, 7, 0});
	while (!q.empty()) {
		auto now = q.front();
		q.pop();
		if (now.x == 7 && now.y == 0 || now.t == 8) {
			cout << 1;
			return 0;
		}
		for (int i = 0; i < 9; ++i) {
			int nx = now.x + dx[i];
			int ny = now.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= 8 || ny >= 8 || visited[ny][nx][now.t + 1]) continue;
			if (ny - now.t >= 0 && input[ny - now.t][nx] == '#') continue;
			if (ny - now.t - 1 >= 0 && input[ny - now.t - 1][nx] == '#') continue;
			visited[ny][nx][now.t + 1] = true;
			q.push({nx, ny, now.t + 1});
		}
	}
	cout << 0;
	return 0;
}
