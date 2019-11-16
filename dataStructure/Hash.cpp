/*
Hash with chaining and linked list
*/
#include <iostream>
#include <list>
#include <string>
#define MAX 11
#define PRIME 29
using namespace std;
typedef struct Data{
    string name;
    int score;
}Data;
bool operator==(Data a, Data b){
    if(a.name.compare(b.name)==0) return true;
    else return false;
}
list<Data> lst[MAX];
unsigned int calHash(string s){//calculate hash value referred to na982
    unsigned int key=0,p=1;
    for(int i=0;i<s.size();++i){
        key+=((unsigned int)s[i])*p;
        p*=PRIME;
    }
    return key%MAX;
}
bool find(string s){//check if the element is already checked in
    unsigned int key = calHash(s);
    for(list<Data>::iterator it=lst[key].begin();it!=lst[key].end();++it){
        if(it->name.compare(s)==0){
            //cout<<key<<' ';
            return true;
        }
    }
    return false;
}
bool add(Data d){//add an element
    if(find(d.name)) return false;
    lst[calHash(d.name)].push_back(d);
    return true;
}
bool remove(Data d){//remove an element
    if(!find(d.name)) return false;
    unsigned int key = calHash(d.name);
    for(list<Data>::iterator it=lst[key].begin();it!=lst[key].end();++it){
        if(it->name.compare(d.name)==0){
            lst[key].erase(it);
            return true;
        }
    }
    return false;
}
bool modify(Data d){//modify an element
    if(!find(d.name)) return false;
    unsigned int key = calHash(d.name);
    for(list<Data>::iterator it=lst[key].begin();it!=lst[key].end();++it){
        if(it->name.compare(d.name)==0){
            *it=d;
            return true;
        }
    }
    return false;
}
int main(){
    Data temp;
    Data input[10]={{"이정태",77},{"박성민",78},{"민경해",88},{"김준수",91},{"김인성",83},{"오현석",85},{"최신범",73},{"송진수",94},{"우민정",81},{"이종헌",100}};
    for(int i=0;i<10;++i) add(input[i]);
    for(int key=0;key<MAX;++key){
        for(list<Data>::iterator it=lst[key].begin();it!=lst[key].end();++it){
            cout<<"key : "<<key<<" name : "<<it->name<<" score : "<<it->score<<'\n';
        }
    }
    for(int i=5;i<10;++i) remove(input[i]);
    temp.name="이정태";
    temp.score=100;
    modify(temp);
    for(int key=0;key<MAX;++key){
        for(list<Data>::iterator it=lst[key].begin();it!=lst[key].end();++it){
            cout<<"key : "<<key<<" name : "<<it->name<<" score : "<<it->score<<'\n';
        }
    }
    
    return 0;
}