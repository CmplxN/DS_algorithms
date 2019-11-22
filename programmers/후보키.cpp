/*
가능한 릴레이션 조합을 비트로 표시
비트 on 갯수를 기준으로 오름차순 정렬
정렬된 비트순으로
이미 합격한 비트들이 부분집합이 되는지 최소성 테스트(bit &시 기존 합격비트가 나오는가)
최소성 테스트 합격시 유일성 테스트(문자열 단순 합친후 unordered_set)
테스트에 성공한 비트는 ans 벡터에 push_back
*/
#include <bits/stdc++.h>
using namespace std;
int col_no,case_no,row_no,close;
int checker[8]={1,2,4,8,16,32,64,128};
typedef struct bits{ int data; }bits;
vector<bits> cases;
bool operator<(bits a, bits b){
    int an=0,bn=0;
    for(int i = 0 ; i < col_no ; ++i ){
        if(a.data&(1<<i)) an++;
        if(b.data&(1<<i)) bn++;
    }
    return an<bn;
}
bool check_valid(vector<vector<string>> &relation, bits b){
    unordered_set<string> us;
    vector<int> focus;
    string s;
    for(int i = 0 ; i < col_no ; ++i ) if(b.data&(1<<i)) focus.push_back(i);
    for(int i = 0 ; i < row_no ; ++i ){
        s.clear();
        for (int j = 0 ; j < focus.size() ; ++j) s+=relation[i][focus[j]];
        if(us.find(s)!=us.end()) return false;
        us.insert(s);
    }
    return true;
}
int solution(vector<vector<string>> relation) {
    vector<int> ans;
    bool nomore;
    col_no = relation[0].size();
    row_no = relation.size();
    case_no=1;
    for(int i=0;i<col_no;++i) case_no*=2;
    for(int i = 1 ; i < case_no ; ++i ) cases.push_back({i});
    sort(cases.begin(),cases.end());
    for(int i = 0 ; i < cases.size(); ++i){
        nomore=false;
        for(int j=0;j<ans.size();++j){
            if((cases[i].data&ans[j])==ans[j]){
                nomore=true;
                break;
            }
        }
        if(nomore) continue;
        if(check_valid(relation,cases[i])) ans.push_back(cases[i].data);
    }
    return ans.size();
}
