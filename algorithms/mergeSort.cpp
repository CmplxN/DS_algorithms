/*
 mergesort by arrays
 later to be coded by linkedlist
*/
#include <iostream>
#include <vector>
#define SIZE 11
using namespace std;
typedef struct Data{
    int a;
}Data;
bool operator<(Data a, Data b){
    return a.a<b.a;
}
void merge(vector<Data> &v, int s, int mid, int e){
    int first, second;
    first=s;
    second=mid+1;
    vector<Data> copier;
    //first와 second중 하나가 다 소모될 때 까지 비교 및 복사
    while(first<=mid&&second<=e){
        if(v[first]<v[second]){
            copier.push_back(v[first]);
            first++;
        }
        else{
            copier.push_back(v[second]);
            second++;
        }
    }
    //소모되지 않고 남은 것들 처리
    if(first<=mid){
        for(int i=first ; i<=mid; ++i) copier.push_back(v[first++]); 
    }
    else{
        for(int i=second ; i<=e; ++i) copier.push_back(v[second++]);
    }
    //v에 다시 넣음
    for(int i=0;i<copier.size();++i) v[i+s]=copier[i];
}
void merge_sort(vector<Data> &v, int s, int e){
    int mid;
    if(s<e){
        mid=(s+e)/2;
        merge_sort(v, s, mid);
        merge_sort(v, mid+1, e);
        merge(v, s, mid, e);
    }
}

int main(){
    Data td;
    vector <Data> v;
    for(int i = 0 ; i < SIZE ; ++i){
        td.a=SIZE-i;
        v.push_back(td);
    } 
    for(int i = 0 ; i < SIZE ; ++i){
        cout<<v[i].a<<' ';
    }
    cout<<'\n';
    merge_sort(v,0,SIZE-1);
    for(int i = 0 ; i < v.size() ; ++i){
        cout<<v[i].a<<' ';
    }
    return 0;
}
