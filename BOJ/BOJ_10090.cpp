#include <bits/stdc++.h>
using namespace std;
long long ans;
void merge(vector<int> &v, int left, int mid, int right){
	vector<int> rtn;
	int l=left,r=mid+1;
	while(l<=mid&&r<=right){
		if(v[l]<=v[r]) {
			ans+=(r-mid-1);
			rtn.push_back(v[l++]);
		}
		else rtn.push_back(v[r++]);
	}
	while(l<=mid) {
		ans+=(r-mid-1);
		rtn.push_back(v[l++]);
	}
	while(r<=right)	rtn.push_back(v[r++]);
	for(int i=0;i<rtn.size();++i) v[left+i]=rtn[i];
}
void dq(vector<int> &v,int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		dq(v, left, mid);
		dq(v, mid + 1, right);
		merge(v, left, mid, right);
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int n, input;
	vector<int> v;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> input;
		v.push_back(input);
	}
	dq(v, 0, v.size() - 1);
	cout << ans;
}
