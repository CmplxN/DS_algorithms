#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	long long num;
	int dep;
	bool mini;
}info;
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	long long A, B, min = 0;
	cin >> A >> B;
	queue<info> q;
	q.push({A, 0, false});
	while (!q.empty()) {
		auto it = q.front();
		if (it.num == B) {
			cout << it.dep + 1;
			return 0;
		}
		if (!it.mini && B < it.num)
			break;
		q.pop();
		if (it.num * 10 + 1 <= B) q.push({it.num * 10 + 1, it.dep + 1, true});
		if (it.num * 2 <= B) q.push({it.num * 2, it.dep + 1, it.mini});
	}
	cout << -1;
	return 0;
}
