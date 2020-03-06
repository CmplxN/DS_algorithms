#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	int cheese, french;
}info;
int n,c,f;
info limit;
int dp[333][333];
vector<info> v;
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>limit.cheese>>limit.french;
	for(int i=0;i<n;++i){
		cin>>c>>f;
		v.push_back({c,f});
	}
	for(int i=0;i<n;++i){
		for(int j=limit.cheese;j>0;--j){
			if(j-v[i].cheese<0)
				continue;
			for(int k=limit.french;k>0;--k) {
				if (k-v[i].french >= 0)
					dp[j][k] = max(dp[j][k], dp[j-v[i].cheese][k-v[i].french] + 1);
			}
		}
	}
	cout<<dp[limit.cheese][limit.french];
	return 0;
}
