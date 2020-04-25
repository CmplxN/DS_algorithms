#include <bits/stdc++.h>
using namespace std;
typedef struct coord{
	int x,y,z,idx;
}coord;
typedef struct mst{
	int from,to,dist;
}mst;
bool operator<(mst a, mst b){
	return a.dist > b.dist;
}
int n,parent[100000], height[100000];
long long ans;
bool cmpByX(coord a, coord b){
	return a.x<b.x;
}
bool cmpByY(coord a, coord b){
	return a.y<b.y;
}
bool cmpByZ(coord a, coord b){
	return a.z<b.z;
}
int find(int tar) {
	if (parent[tar] == tar) return tar;
	return find(parent[tar]);
}
void doUnion(int a, int b) {
	int A = find(a);
	int B = find(b);
	if (A == B) return;
	if (height[A] < height[B]) parent[A] = B;
	else if (height[A] > height[B]) parent[B] = A;
	else {
		parent[B] = A;
		height[A]++;
	}
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin >> n;
	vector<coord> v(n);
	priority_queue<mst> pq;
	for (int i = 0; i < n; ++i) {
		cin >> v[i].x >> v[i].y >> v[i].z;
		v[i].idx = i;
	}
	sort(v.begin(), v.end(), cmpByX);
	for (int i = 0; i < n - 1; ++i) {
		pq.push({v[i].idx,v[i+1].idx,v[i+1].x-v[i].x});
		pq.push({v[i+1].idx,v[i].idx,v[i+1].x-v[i].x});
	}
	sort(v.begin(), v.end(), cmpByY);
	for (int i = 0; i < n - 1; ++i) {
		pq.push({v[i].idx,v[i+1].idx,v[i+1].y-v[i].y});
		pq.push({v[i+1].idx,v[i].idx,v[i+1].y-v[i].y});
	}
	sort(v.begin(), v.end(), cmpByZ);
	for (int i = 0; i < n - 1; ++i) {
		pq.push({v[i].idx,v[i+1].idx,v[i+1].z-v[i].z});
		pq.push({v[i+1].idx,v[i].idx,v[i+1].z-v[i].z});
	}
	for(int i=0;i<100000;++i){
		parent[i]=i;
		height[i]=1;
	}
	while(!pq.empty()){
		auto now = pq.top();
		pq.pop();
		if(find(now.from) == find(now.to)) continue;
		doUnion(now.from,now.to);
		ans+=now.dist;
	}
	cout<<ans;
	return 0;
}
