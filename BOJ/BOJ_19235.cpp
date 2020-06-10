#include <bits/stdc++.h>
using namespace std;
int n,t,x,y,score,cnt;
int field[10][10];
void clean_right() {
	int num = 0;
	for (int i = 0; i < 4; ++i)
		if (field[i][5] != 0)
			num = 1;
	for (int i = 0; i < 4; ++i)
		if (field[i][4] != 0)
			num = 2;
	if (num == 0) return;
	for (int i = 9 - num; i > 3; --i)
		for (int j = 0; j < 4; ++j)
			field[j][i + num] = field[j][i];
	for (int i = 0; i < 4; ++i)
		field[i][5] = 0;
	for (int i = 0; i < 4; ++i)
		field[i][4] = 0;
}
void clean_down() {
	int num = 0;
	for (int i = 0; i < 4; ++i)
		if (field[5][i] != 0)
			num = 1;
	for (int i = 0; i < 4; ++i)
		if (field[4][i] != 0)
			num = 2;
	if (num == 0) return;
	for (int i = 9 - num; i > 3; --i)
		for (int j = 0; j < 4; ++j)
			field[i + num][j] = field[i][j];
	for (int i = 0; i < 4; ++i)
		field[5][i] = 0;
	for (int i = 0; i < 4; ++i)
		field[4][i] = 0;
}
void gravity_down() {
	for (int j = 9; j > 3; --j) {
		for (int i = 0; i < 4; ++i) {
			int tj = j;
			if (field[tj][i] == 0) continue;
			int copy = field[tj][i];
			if (field[tj][i] == field[tj][i + 1]) {
				field[tj][i] = 0;
				field[tj][i + 1] = 0;
				do {
					tj++;
				} while (tj < 10 && field[tj][i] == 0 && field[tj][i + 1] == 0);
				field[tj - 1][i] = copy;
				field[tj - 1][i + 1] = copy;
				continue;
			}
			if (i != 0 && field[tj][i] == field[tj][i - 1]) {
				field[tj][i] = 0;
				field[tj][i - 1] = 0;
				do {
					tj++;
				} while (tj < 10 && field[tj][i] == 0 && field[tj][i - 1] == 0);
				field[tj - 1][i] = copy;
				field[tj - 1][i - 1] = copy;
				continue;
			}
			field[tj][i] = 0;
			do {
				tj++;
			} while (tj < 10 && field[tj][i] == 0);
			field[tj - 1][i] = copy;
		}
	}
}
void gravity_right() {
	for (int j = 9; j > 3; --j) {
		for (int i = 0; i < 4; ++i) {
			int tj = j;
			if (field[i][tj] == 0) continue;
			int copy = field[i][tj];
			if (field[i][tj] == field[i + 1][tj]) {
				field[i][tj] = 0;
				field[i + 1][tj] = 0;
				do {
					tj++;
				} while (tj < 10 && field[i][tj] == 0 && field[i + 1][tj] == 0);
				field[i][tj - 1] = copy;
				field[i + 1][tj - 1] = copy;
				continue;
			}
			if (i != 0 && field[i][tj] == field[i - 1][tj]) {
				field[i][tj] = 0;
				field[i - 1][tj] = 0;
				do {
					tj++;
				} while (tj < 10 && field[i][tj] == 0 && field[i - 1][tj] == 0);
				field[i][tj - 1] = copy;
				field[i - 1][tj - 1] = copy;
				continue;
			}
			field[i][tj] = 0;
			do {
				tj++;
			} while (tj < 10 && field[i][tj] == 0);
			field[i][tj - 1] = copy;
		}
	}
}
bool check_right() {
	vector<int> v;
	for (int i = 6; i < 10; ++i) {
		bool go = true;
		for (int j = 0; j < 4; ++j)
			if (field[j][i] == 0) {
				go = false;
				break;
			}
		if (go)
			v.push_back(i);
	}
	if (v.empty()) return false;
	for (auto it : v)
		for (int i = 0; i < 4; ++i)
			field[i][it] = 0;
	score += v.size();
	gravity_right();
	return true;
}
bool check_down() {
	vector<int> v;
	for (int i = 6; i < 10; ++i) {
		bool go = true;
		for (int j = 0; j < 4; ++j)
			if (field[i][j] == 0) {
				go = false;
				break;
			}
		if (go)
			v.push_back(i);
	}
	if (v.empty()) return false;
	for (auto it : v)
		for (int i = 0; i < 4; ++i)
			field[it][i] = 0;
	score += v.size();
	gravity_down();
	return true;
}
void new_input(int t, int x, int y) {
	if (t == 1) {
		int nx = x + 1;
		while (nx <= 10) {
			if (nx == 10 || field[y][nx]) {
				field[y][nx - 1] = n + 3;
				break;
			}
			nx++;
		}
		int ny = y + 1;
		while (ny <= 10) {
			if (ny == 10 || field[ny][x]) {
				field[ny - 1][x] = n + 3;
				break;
			}
			ny++;
		}
	} else if (t == 2) {
		int nx = x + 2;
		while (nx <= 10) {
			if (nx == 10 || field[y][nx]) {
				field[y][nx - 1] = n + 3;
				field[y][nx - 2] = n + 3;
				break;
			}
			nx++;
		}
		int ny = y + 1;
		while (ny <= 10) {
			if (ny == 10 || field[ny][x] || field[ny][x + 1]) {
				field[ny - 1][x] = n + 3;
				field[ny - 1][x + 1] = n + 3;
				break;
			}
			ny++;
		}
	} else {
		int nx = x + 1;
		while (nx <= 10) {
			if (nx == 10 || field[y][nx] || field[y + 1][nx]) {
				field[y][nx - 1] = n + 3;
				field[y + 1][nx - 1] = n + 3;
				break;
			}
			nx++;
		}
		int ny = y + 2;
		while (ny <= 10) {
			if (ny == 10 || field[ny][x]) {
				field[ny - 1][x] = n + 3;
				field[ny - 2][x] = n + 3;
				break;
			}
			ny++;
		}
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n;
	while (n--) {
		cin >> t >> y >> x;
		new_input(t, x, y);
		while (check_right());
		clean_right();
		while (check_down());
		clean_down();
	}
	for (auto &i : field) for (int j : i) if (j != 0) cnt++;
	cout << score << '\n' << cnt;
	return 0;
}
