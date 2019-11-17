/*
 * 1부터 N/2길이까지 글자 잘라서 완탐
 *자릿수 상관없이 반복되면 +1글자라고 생각하여 엄청 고생함
*/
#include <string>
#include <vector>
using namespace std;
int solution(string s) {
    int answer = s.size();
    int result;
    int consec;
    string substr;
    for(int i= 1; i <= s.size()/2 ; ++i){ // i길이로
        int j;
        result=0;
        consec=-1;
        substr=s.substr(0,i);
        for(j = 0 ; j < s.size()-i+1; j=j+i ){//남은길이 1~i이도록
            if(substr.compare(s.substr(j,i))==0){
                consec++;
            }
            else{
                if(consec>998) result+=(4+i);
                else if(consec>98) result +=(3+i);
                else if(consec>8) result +=(2+i);
                else if(consec>0) result +=(1+i);
                else result+=i;
                consec=0;
                substr=s.substr(j,i);
            }
        }
        if(j==s.size()){//남은 자리가 딱 맞음
            if(consec>998) result+=(4+i);
            else if(consec>98) result +=(3+i);
            else if(consec>8) result +=(2+i);
            else if(consec>0) result +=(1+i);
            else result+=i;
        }
        else{//남은자리가 딱 맞지는 않음
            result+=(s.size()-j);//안떨어지는 자리
            if(consec>998) result+=(4+i);
            else if(consec>98) result +=(3+i);
            else if(consec>8) result +=(2+i);
            else if(consec>0) result +=(1+i);
            else result+=i;
        }
        answer=answer<result?answer:result;
    }
    return answer;
}
