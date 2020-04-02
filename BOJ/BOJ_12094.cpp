#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int n,ans,cpy[11][22][22],pows[12];
bool act(int d,int dir, int sign) {
	int maxi = 0;
	if (dir == 0) {
		if (sign == 0) {
			for (int i = 1; i <= n; ++i) {
				int v[22];
				int size=0;
				int prev = 0;
				for (int j = 1; j <= n; ++j) {
					if (cpy[d][i][j] == 0) continue;
					if (cpy[d][i][j] == prev) {
						v[size-1]+=cpy[d][i][j];
						prev=0;
					} else {
						prev=cpy[d][i][j];
						v[size++]=cpy[d][i][j];
					}
				}
				int k = 1;
				for (k; k <= size; ++k) {
					maxi=max(maxi,v[k-1]);
					cpy[d][i][k] = v[k - 1];
				}
				for (k; k <= n; ++k) cpy[d][i][k] = 0;
			}
		} else {
			for (int i = 1; i <= n; ++i) {
				int v[22];
				int size=0;
				int prev=0;
				for (int j = n; j >= 1; --j) {
					if (cpy[d][i][j] == 0) continue;
					if (cpy[d][i][j] == prev) {
						v[size-1]+=cpy[d][i][j];
						prev=0;
					} else {
						prev=cpy[d][i][j];
						v[size++]=cpy[d][i][j];
					}
				}
				int k = 1;
				for (k; k <= size; ++k){
					maxi=max(maxi,v[k-1]);
					cpy[d][i][n - k + 1] = v[k - 1];
				}
				for (k; k <= n; ++k) cpy[d][i][n - k + 1] = 0;
			}
		}
	} else {
		if (sign == 0) {
			for (int j = 1; j <= n; ++j) {
				int v[22];
				int size=0;
				int prev=0;
				for (int i = 1; i <= n; ++i) {
					if (cpy[d][i][j] == 0) continue;
					if (cpy[d][i][j] == prev) {
						v[size-1]+=cpy[d][i][j];
						prev=0;
					} else {
						prev=cpy[d][i][j];
						v[size++]=cpy[d][i][j];
					}
				}
				int k = 1;
				for (k; k <= size; ++k){
					maxi=max(maxi,v[k-1]);
					cpy[d][k][j] = v[k - 1];
				}
				for (k; k <= n; ++k) cpy[d][k][j] = 0;
			}
		} else {
			for (int j = 1; j <= n; ++j) {
				int v[22];
				int size=0;
				int prev=0;
				for (int i = n; i >= 1; --i) {
					if (cpy[d][i][j] == 0) continue;
					if (cpy[d][i][j] == prev) {
						v[size-1]+=cpy[d][i][j];
						prev=0;
					} else {
						prev=cpy[d][i][j];
						v[size++]=cpy[d][i][j];
					}
				}
				int k = 1;
				for (k; k <= size; ++k) {
					maxi = max(maxi, v[k - 1]);
					cpy[d][n - k + 1][j] = v[k - 1];
				}
				for (k; k <= n; ++k) cpy[d][n - k + 1][j] = 0;
			}
		}
	}
	bool akirame = true;
	for (int k = 1; k <= n; ++k) for (int j = 1; j <= n; ++j){
		if(cpy[d-1][k][j]!=cpy[d][k][j]){
			akirame=false;
			break;
		}
	}
	if(akirame) return false;
	return maxi*pows[MAX-d]>ans;
}
void dfs(int d) {
	if (d == MAX) {
		for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j) ans = ans < cpy[d][i][j] ? cpy[d][i][j] : ans;
		return;
	}
	for(int i=0;i<4;++i){
		for (int k = 1; k <= n; ++k) for (int j = 1; j <= n; ++j) cpy[d+1][k][j]=cpy[d][k][j];
		if(act(d+1,i/2,i%2)) dfs(d+1);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	pows[0] = 1;
	for (int i = 1; i < 12; ++i) pows[i] = pows[i - 1] * 2;
	cin >> n;
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= n; ++j){
		cin >> cpy[0][i][j];
		ans=ans<cpy[0][i][j]?cpy[0][i][j]:ans;
	}
	dfs(0);
	cout << ans;
	return 0;
}
