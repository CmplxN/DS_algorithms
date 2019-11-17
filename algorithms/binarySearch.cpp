/*
    binarySerach : returns Data if it's contained.
    lowerBound : returns the exact same Data or one that is just bigger than the Data.
    upperBound : returns one that is just bigger than the Data.
*/
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef struct Data{
    int data;
}Data;
bool operator<(Data a, Data b){
    return a.data<b.data;
}
bool operator>(Data a, Data b){
    return a.data>b.data;
}
Data *binarySearch(vector<Data> v, Data target){
    int left=0, right=v.size()-1, mid;
    while(left<=right){
        mid=(left+right)/2;
        if(target<v[mid]){
            right=mid-1;
        }
        else if(target>v[mid]){
            left=mid+1;
        }
        else{
            return &v[mid];
        }
    }
    return NULL;
}
Data *lowerBound(vector<Data> v, Data target){
    int left=0, right=v.size(), mid;
    mid=(left+right)/2;
    while(left<right){
        mid=(left+right)/2;
        if(target>v[mid]){
            left=mid+1;
        }
        else{
            right=mid;
        }
    }
    return &v[right];
}
Data *upperBound(vector<Data> v, Data target){
    int left=0, right=v.size(), mid;
    mid=(left+right)/2;
    while(left<right){
        mid=(left+right)/2;
        if(target<v[mid]){
            right=mid;
        }
        else{
            left=mid+1;
        }
    }
    return &v[right];
}
int main(){
    vector<Data> v;
    Data t;
    Data d[11]={{1},{2},{3},{4},{5},{6},{7},{8},{9},{10},{100}};
    cin>>t.data;
    for(int i=0;i<11;++i) v.push_back(d[i]);
    for(int i=0;i<11;++i) cout<<v[i].data<<' ';
    cout<<endl;
    if(binarySearch(v,t)!=NULL){
        cout<<"Bst : "<<binarySearch(v,t)->data;
    }
    else cout<<"Not in the vector";
    cout<<" LB : "<<lowerBound(v,t)->data<<" UB : "<<upperBound(v,t)->data<<endl;
    return 0;
}