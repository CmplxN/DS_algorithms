#include <string>
#include <vector>
#include <algorithm>
typedef struct info{
    double ratio;
    int no;
}info;
using namespace std;
bool operator<(info a, info b){
    if(a.ratio==b.ratio) return a.no<b.no;
    return a.ratio>b.ratio;
}
vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<int> success(N+2);
    vector<int> reach(N+2);
    vector<info> gogo;
    info temfo;
    for(int i=0;i<stages.size();++i){
        for(int j=1;j<=stages[i];++j){
            reach[j]++;
            if(j<stages[i]) success[j]++;
        }
    }
    for(int i = 1 ; i <= N ; ++i){
        if(reach[i]==0) temfo.ratio=0.0f;
        else temfo.ratio=1.0f-((double)success[i]/(double)reach[i]);
        temfo.no=i;
        gogo.push_back(temfo);
    }
    sort(gogo.begin(),gogo.end());
    for(int i = 0 ; i < gogo.size() ; ++i) answer.push_back(gogo[i].no);
    return answer;
}
