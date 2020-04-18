#include <bits/stdc++.h>
using namespace std;
typedef struct info{
	int a,b,c;
}info;
bool operator<(info a, info b){
	if(a.a==b.a){
		if(a.b==b.b){
			return a.c<b.c;
		}
		return a.b<b.b;
	}
	return a.a<b.a;
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	int water[3];
	set<info> visited;
	set<int> ans;
	queue<info> q;
	cin>>water[0]>>water[1]>>water[2];
	q.push({0,0,water[2]});
	visited.insert({0,0,water[2]});
	while(!q.empty()){
		info now = q.front();
		q.pop();
		if(now.a!=water[0]){
			if(now.b>0){
				int amount = min(now.b,water[0]-now.a);
				if(visited.find({now.a+amount,now.b-amount,now.c})==visited.end()) {
					q.push({now.a + amount, now.b - amount, now.c});
					visited.insert({now.a + amount, now.b - amount, now.c});
				}
			}
			if(now.c>0){
				int amount = min(now.c,water[0]-now.a);
				if(visited.find({now.a+amount,now.b,now.c-amount})==visited.end()) {
					q.push({now.a + amount, now.b, now.c - amount});
					visited.insert({now.a+amount,now.b,now.c-amount});
				}
			}
		}
		if(now.b!=water[1]){
			if(now.a>0){
				int amount = min(now.a,water[1]-now.b);
				if(visited.find({now.a-amount,now.b+amount,now.c})==visited.end()) {
					q.push({now.a - amount, now.b + amount, now.c});
					visited.insert({now.a-amount,now.b+amount,now.c});
				}
			}
			if(now.c>0){
				int amount = min(now.c,water[1]-now.b);
				if(visited.find({now.a,now.b+amount,now.c-amount})==visited.end()) {
					q.push({now.a, now.b + amount, now.c - amount});
					visited.insert({now.a,now.b+amount,now.c-amount});
				}
				if(now.a==0&&ans.find(now.c - amount)==ans.end())
					ans.insert(now.c-amount);
			}
		}
		if(now.c!=water[2]){
			if(now.b>0){
				int amount = min(now.b,water[2]-now.c);
				if(visited.find({now.a,now.b-amount,now.c+amount})==visited.end()) {
					q.push({now.a, now.b - amount, now.c + amount});
					visited.insert({now.a,now.b-amount,now.c+amount});
				}
				if(now.a==0&&ans.find(now.c + amount)==ans.end())
					ans.insert(now.c+amount);
			}
			if(now.a>0){
				int amount = min(now.a,water[2]-now.c);
				if(visited.find({now.a - amount, now.b, now.c + amount})==visited.end()) {
					q.push({now.a - amount, now.b, now.c + amount});
					visited.insert({now.a - amount, now.b, now.c + amount});
				}
				if(now.a-amount==0&&ans.find(now.c + amount)==ans.end())
					ans.insert(now.c+amount);
			}
		}
	}
	for(auto it : ans) cout<<it<<' ';
	return 0;
}
