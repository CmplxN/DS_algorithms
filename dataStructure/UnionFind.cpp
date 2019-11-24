/*
union find using tree + balancing
coded after reading https://bowbowbow.tistory.com/
*/
#include <bits/stdc++.h>
#define SIZE 17
using namespace std;
vector<int> parent;
vector<int> height;
int find_parent(int key){
    if(parent[key]==key) return key;
    int rtn=key;
    while(parent[rtn]!=rtn){
        rtn=parent[rtn];
    }
    return rtn;
}
void do_union(int un1, int un2){//un1 and un2 unify
    int un1_p=find_parent(un1);
    int un2_p=find_parent(un2);
    if(un1_p==un2_p) return;
    if(height[un1_p]>height[un2_p]){
        parent[un2_p]=un1_p;
    }
    else if(height[un1_p]<height[un2_p]){
        parent[un1_p]=un2_p;
    }
    else{
        parent[un1_p]=un2_p;
        height[un2_p]++;
    }        
}
int main(){
    for(int i = 0 ; i<SIZE;++i){
        parent.push_back(i);
        height.push_back(1);
    }
    do_union(1,2);
    do_union(1,3);
    do_union(1,4);
    do_union(11,12);
    do_union(13,12);
    do_union(11,14);
    do_union(4,11);
    for(int i = 0 ; i<SIZE;++i){
        cout<<parent[i]<<' ';
    }
    cout<<'\n';
    for(int i = 0 ; i<SIZE;++i){
        cout<<find_parent(i)<<' ';
    }
    return 0;
}