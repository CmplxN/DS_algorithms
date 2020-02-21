#include <bits/stdc++.h>
using namespace std;
int n,k,input;
multiset<int> ms;
multiset<int>::iterator ms_it = ms.begin();
vector<int> v;
long long int ans;
void ms_insert(int i){
	ms.insert(i);
	if(ms.size() <= 2) {
		ms_it = ms.begin();
		return ;
	}
	if(ms.size() % 2 == 0) {
		if (*ms_it > i)
			ms_it--;
	}
	else {
		if (*ms_it <= i)
			ms_it++;
	}
}
void ms_delete(int tar){
	auto itt = ms.find(tar);
	if(ms.size() % 2 == 0){
		if(tar <= *ms_it) {
			if(tar == *ms_it)
				itt = ms_it;
			ms_it++;
		}
	}
	else{
		if(tar >= *ms_it){
			if(tar == *ms_it)
				itt = ms_it;
			ms_it--;
		}
	}
	ms.erase(itt);
}
int main(){
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios_base::sync_with_stdio(false);
	cin>>n>>k;
	for(int i = 0 ; i < k ; ++i){
		cin>>input;
		v.push_back(input);
		ms_insert(input);
	}
	ans += *ms_it;
	for(int i = 0 ; i < n - k ; ++i){
		cin>>input;
		v.push_back(input);
		ms_delete(v[i]);
		ms_insert(input);
		ans += *ms_it;
	}
	cout<<ans;
	return 0;
}
