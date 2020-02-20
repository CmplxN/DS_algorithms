#include <bits/stdc++.h>
using namespace std;
int tree1[444444];
int tree2[444444];
int find_max(int l, int r){
	int rtn = -1;
	while(l<=r){
		if(l%2==1 && tree2[l] != 0)
			rtn = max(rtn, tree2[l]);
		if(r%2==0 && tree2[r] != 0)
			rtn = max(rtn, tree2[r]);
		l=(l+1)/2;
		r=(r-1)/2;
	}
	return rtn;
}
int find_min(int l, int r){
	int rtn = 2147483647;
	while(l<=r){
		if(l%2==1 && tree1[l] != 0)
			rtn = min(rtn, tree1[l]);
		if(r%2==0 && tree1[r] != 0)
			rtn = min(rtn, tree1[r]);
		l=(l+1)/2;
		r=(r-1)/2;
	}
	return rtn;
}
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n,m,input,l,r,var,log=0;
	cin>>n>>m;
	var = n - 1;
	while(var != 0) {
		var /= 2;
		log++;
	}
	var = pow(2, log);
	for(int i=0;i<n;++i) {
		cin >> tree1[var + i];
		tree2[var + i] = tree1[var + i];
	}
	for(int i=var-1;i>0;--i) {
		tree1[i] = min(tree1[2 * i], tree1[2 * i + 1]);
		tree2[i] = max(tree2[2 * i], tree2[2 * i + 1]);
	}
	for(int i=0;i<m;++i){
		cin>>l>>r;
		cout<<find_min(var + l - 1,var + r - 1)<<' '<<find_max(var + l - 1,var + r - 1)<<'\n';
	}
	return 0;
}
