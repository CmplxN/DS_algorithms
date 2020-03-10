#include <bits/stdc++.h>
using namespace std;
int n,m,visited[51][51];
int dx[4]={-1,0,1,0};
int dy[4]={0,-1,0,1};
vector<int> area;
vector<vector<int>> mp;
int dfs(int x, int y, unsigned int no) {
	int rtn = 1;
	visited[y][x] = (int) no;
	for (int i = 0; i < 4; ++i) {
		if ((1 << i & mp[y][x]) != 0) continue;
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx > -1 && ny > -1 && nx < n && ny < m && !visited[ny][nx]) rtn += dfs(nx, ny, no);
	}
	return rtn;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	mp = vector<vector<int>>(m);
	for (int i = 0; i < m; ++i) {
		mp[i] = vector<int>(n);
		for (int j = 0; j < n; ++j) cin >> mp[i][j];
	}
	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j)
			if (!visited[i][j])
				area.push_back(dfs(j, i, area.size() + 1));
	cout << area.size() << '\n' << *max_element(area.begin(), area.end()) << '\n';
	int maxi = 0;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < 4; ++k) {
				if ((1 << k & mp[i][j]) == 0) continue;
				int nx = dx[k] + j;
				int ny = dy[k] + i;
				if (nx > -1 && ny > -1 && nx < n && ny < m) {
					if (visited[i][j] == visited[ny][nx])
						maxi = maxi < area[visited[ny][nx] - 1] ? area[visited[ny][nx] - 1] : maxi;
					else
						maxi = maxi < area[visited[i][j] - 1] + area[visited[ny][nx] - 1] ? area[visited[ny][nx] -
						                                                                         1] +
						                                                                    area[visited[i][j] - 1]
						                                                                  : maxi;
				}
			}
		}
	}
	cout << maxi;
	return 0;
}
