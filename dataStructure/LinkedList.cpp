/*
c-style double linked list
later object-oriented
14.NOV.19
*/
#include <iostream>
#include <stdlib.h>
typedef struct DT{//사용할 자료형
    int data;
}DT;
typedef struct node{//연결리스트의 한 노드
    node *prev;
    node *next;
    DT data;
}node;
typedef struct LinkedList{//연결리스트를 가르키는 포인터
    int size;
    node *head;
}LinkedList;
DT test={1};
bool equals(DT &a, DT &b){
    if(a.data==b.data) return true;
    else return false;
}
void printDT(DT &a){
    std::cout<<a.data<<' ';
}
node* initNode(DT &data){//해당 데이터로 초기화, prev, next는 미설정
    node* newNode = (node*) malloc(sizeof(node));
    newNode->prev=NULL;
    newNode->next=NULL;
    newNode->data=data;
    return newNode;
}
bool insertNode(LinkedList *LL, node *nd, DT &data){//nd 다음에 노드 삽입
    node* newNode = initNode(data);
    if(LL->size==0){//빈 연결리스트였다면 노드 생성하고 그걸로 헤드도 설정
        LL->size=1;
        LL->head=initNode(data);
        LL->head->prev=LL->head->next=LL->head;
        return true;
    }
    if(nd==NULL) {//있지도 않은 곳에 넣으라고 하면 거절한다.
        free(newNode);
        return false;
    }
    //비어있지 않고 노드를 잘 지정해 준 경우
    newNode->next=nd->next;
    newNode->prev=nd;
    nd->next->prev=newNode;
    nd->next=newNode;
    LL->size++;
    return true;
}
bool eraseNode(LinkedList *LL, node *nd){//nd 노드 삭제 헤드가 삭제될 경우 처리해줌
    if(nd==NULL||LL->size==0) return false;//애초에 빈 리스트라던가 비울 노드라고 준게 무효하면
    if(LL->size==1){//삭제하려는데 그게 유일한 노드임
        LL->head=NULL;
        LL->size=0;
        free(nd);
        return true;
    }
    if(LL->head==nd){//삭제할게 유일노드는 아니지만 헤드면 헤드를 원래헤드 다음으로 해줌
        LL->head=nd->next;
    }
    //삭제할게 헤드가 아님
    nd->prev->next=nd->next;
    nd->next->prev=nd->prev;
    LL->size--;
    free(nd);    
    return true;
}
node* searchNode(LinkedList *LL, DT &data){//노드 탐색해서 찾으면 노드를 아니면 NULL을
    node* itNode=LL->head;
    do{
        if(equals(data,itNode->data)) return itNode;
    }while(LL->head!=itNode);//한바퀴 돌아서 같아질때까지 
    return NULL;  
}
LinkedList* initList(){//리스트 시작(노드 하나도 생성)
    LinkedList* LL = (LinkedList*) malloc(sizeof(LinkedList));
    LL->size = 0;
    LL->head = NULL;
    return LL;
}
bool destroyList(LinkedList **LL){//리스트 전부 삭제 헤드의 prev를 하나씩 지워버림
    while((*LL)->size!=0){
        eraseNode(*LL,(*LL)->head->prev);
    }
    free(*LL);
    *LL=NULL;
    return true;
}
void printList(LinkedList *LL){
    if(LL==NULL) return;
    node *nd=LL->head;
    if(LL->size==0){
        std::cout<<"no elements ";
        return;
    }
    for(int i = 0 ; i < LL->size; ++i ){
        printDT(nd->data);
        nd=nd->next;
    }
    return;
}
int main(){
    LinkedList *LL = initList();
    for(int i = 0 ; i < 11 ; ++i ){
        test.data=i;
        insertNode(LL,LL->head,test);
    }
    printList(LL);
    std::cout<<'\n';
    eraseNode(LL,LL->head->next->next->next);
    printList(LL);
    std::cout<<'\n';
    destroyList(&LL);
    if(LL==NULL) std::cout<<"NULL";
    else printList(LL);
    
    return 0;
}