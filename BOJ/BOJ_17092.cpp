#include <bits/stdc++.h>
using namespace std;
int H,W,N,r,c;
map<pair<int,int>, int> mp;
long long ans[10];
void execute(int x, int y) {
	if (mp.find({x, y}) == mp.end())
		mp[{x, y}] = 1;
	else
		mp[{x, y}]++;
}
void insert(int x, int y) {
	if (x - 2 >= 0 && x < W) {
		if (y - 2 >= 0 && y < H)
			execute(x - 2, y - 2);
		if (y - 1 >= 0 && y + 1 < H)
			execute(x - 2, y - 1);
		if (y + 2 < H)
			execute(x - 2, y);
	}
	if (x - 1 >= 0 && x + 1 < W) {
		if (y - 2 >= 0 && y < H)
			execute(x - 1, y - 2);
		if (y - 1 >= 0 && y + 1 < H)
			execute(x - 1, y - 1);
		if (y + 2 < H)
			execute(x - 1, y);
	}
	if (x + 2 < W) {
		if (y - 2 >= 0 && y < H)
			execute(x, y - 2);
		if (y - 1 >= 0 && y + 1 < H)
			execute(x, y - 1);
		if (y + 2 < H)
			execute(x, y);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> H >> W >> N;
	for (int i = 0; i < N; ++i) {
		cin >> r >> c;
		insert(c - 1, r - 1);
	}
	for (auto it : mp)
		ans[it.second]++;
	long long total = (long long) (H - 2) * (long long) (W - 2);
	for (auto an : ans)
		total -= an;
	ans[0] = total;
	for (auto an : ans)
		cout << an << '\n';
	return 0;
}
