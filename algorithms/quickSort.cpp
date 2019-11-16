/*
 quickSort
 choose pivot by selecting 3 weak-random numbers then picking the median.
*/
#include <iostream>
#include <vector>
#define SIZE 19
#define RANDOMIZER 111
using namespace std;
int randomizer;
typedef struct Data{
    int a;
}Data;
bool operator<(Data a, Data b){
    return a.a<b.a;
}
bool operator>(Data a, Data b){
    return a.a>b.a;
}
bool operator<=(Data a, Data b){
    return a.a<=b.a;
}
bool operator>=(Data a, Data b){
    return a.a>=b.a;
}
void vector_swap(vector<Data> &v, int a, int b){//vector의 idx a와 b 교환
    Data temp;
    temp=v[a];
    v[a]=v[b];
    v[b]=temp;
}
void find_mid(vector<Data> &v, int lm, int rm, int r){// compare leftmost, rightmost, random. the median goes leftmost to be the pivot
    if(v[lm]<v[rm]){
        if(v[rm]<v[r]){//choose v[rm]
            vector_swap(v,rm,lm);
        }
        else if(v[lm]<v[r]){//v[lm]<v[r]<=v[rm] choose v[r]
            vector_swap(v,r,lm);
        }
        else{//v[r]<=v[lm]<v[rm] choose v[lm]-> no change

        }
    }
    else{
        if(v[lm]<v[r]){//v[rm]<=v[lm]<v[r] choose v[lm] -> no change

        }
        else if(v[rm]<v[r]){//v[rm]<v[r]<v[lm] choose v[r]
            vector_swap(v,r,lm);
        }
        else{//v[r]<=v[rm]<=v[lm] choose v[rm]
            vector_swap(v,rm,lm);
        }
    }
}
void quick_sort(vector<Data> &v, int s, int e){
   if(s<e){
        randomizer=(randomizer+RANDOMIZER)%(e-s+1);
        find_mid(v,s,e,randomizer+s);
    }
    Data pivot=v[s];
    int first=s+1;
    int second=e;
    //cout<<" pivot "<<pivot.a<<' ';
    while(first<=second){
        while(v[first]<=pivot&&first<=e){
            first++;
            //if(first>SIZE-1) cout<<"first "<<first<<" first>e "<<v[first].a<<"why ok?\n";
            //if(first<=SIZE-1) first++;
            //else break;
        }
        //cout<<"\nv[first] "<<v[first].a;
        while(v[second]>=pivot&&second>=s+1){
            //if(second>=0) second--;
            //else break;
            second--;
            //if(second<0) cout<<"second<s\n";
        }
        //cout<<"\nv[second] "<<v[second].a;
        //cout<<first<<' '<<second<<'\n';
        if(first<=second){
            vector_swap(v,first,second);
        }
    }
    //cout<<'\n';
    //cout<<'\n'<<pivot.a<<'\n';
    //for(int i=s;i<=e;++i) cout<<v[i].a<<' ';
    //cout<<"\n\n";
    if(s<e){
        vector_swap(v,s,second);
        quick_sort(v,s,second-1);
        quick_sort(v,second+1,e);
    }
    return;
}
int main(){
    vector<Data> v;
    Data temp;
    for(int i=0 ; i<SIZE; ++i){
        temp.a=SIZE-i;
        v.push_back({(SIZE+i*i*i)%SIZE});
    }
    for(int i=0;i<v.size();++i){
        cout<<v[i].a<<' ';
    }
    cout<<'\n';
    quick_sort(v,0,SIZE-1);
    for(int i=0;i<v.size();++i){
        cout<<v[i].a<<' ';
    }
    cout<<'\n';
    return 0;
}