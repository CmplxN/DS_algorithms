/*
single linked list using class, template
*/
#include <bits/stdc++.h>
using namespace std;
template<typename T>
struct Node{
  public:
    T value;
    struct Node<T> *next; 
};
template<typename T>
class List{
  private:
    Node<T> *head, *tail;
    int size;
  public:
    List() : head(nullptr), tail(nullptr), size(0){}
    ~List() {}
    void push_back(T value){//끝에 노드 삽입
      Node<T> *node = new Node<T>;
      size++;
      node->value= value;
      node->next = nullptr;
      if(head==nullptr){
        head=node;
        tail=node;
      }
      else{
        tail->next=node;
        tail=node;
      }
    }
    void push_front(T value){//앞에 노드 삽입
      Node<T> *node = new Node<T>;
      size++;
      node->value= value;
      if(head==nullptr){
        node->next=nullptr;
        head=node;
        tail=node;
      }
      else{
        node->next=head;
        head=node;
      }
    }
    void add_node(Node<T> *nd, T value){//nd다음에 삽입 head, tail은 안됩니다.
      if(size==0) return;//빈 리스트면 안됩니다.
      if(nd==head){
        push_front(value);
        return;
      }
      if(nd==tail){
        push_back(value);
        return;
      }
      Node<T> *node = new Node<T>;
      size++;
      node->value= value;
      node->next = nd->next;
      nd->next = node;
    }
    void pop_back(){//끝 제거
      if(tail==nullptr) return;
      if(size==1){
        delete tail;
        tail=head=nullptr;
      }
      else{
        Node<T> *temp = head;
        while(temp->next!=tail){
          temp=temp->next;
        }
        delete tail;
        tail=temp;
        tail->next=nullptr;
      }
    }
    void pop_front(){//첫 제거
      if(head==nullptr) return;
      if(size==1){
        delete head;
        tail=head=nullptr;
      }
      else{
        Node<T> *temp = head;
        head=head->next;
        delete temp;
      }
    }
    void del_node(Node<T> *nd){//nd 노드 삭제
      if(nd==nullptr) return;
      if(nd==head){
        pop_front();
        return;
      }
      if(nd==tail){
        pop_back();
        return;
      }
      Node<T> *temp = head;
      while(temp->next!=nd){
         temp=temp->next;
      }
      temp->next=nd->next;
      delete nd;
    }
    Node<T> *find_node(T value){//해당 값을 가지는 첫 노드 포인터 반환
      if(head==nullptr) return nullptr;
      Node<T> *ptr = head;
      while(ptr!=nullptr){
        if(ptr->value==value){
          return ptr;
        }
        ptr=ptr->next;
      }
      return nullptr;
    }
    void delete_list(){
      Node<T> *temp = head;
      while(temp!=nullptr){
        head=temp->next;
        delete temp;
        temp=head;
      }
      delete head;
      size=0;
    }
    void print(){
      Node<T> *ptr = head;
      while(ptr!=nullptr){
        cout<<ptr->value<<"->";
        ptr=ptr->next;
      }
      cout<<"END OF LIST\n";
    }
    int get_size(){
      return size;
    }
    void list_concat(List<T> *l){
      tail->next=l->head;
      tail=l->tail;
      delete l;
    }
};
int main() {
  List<int> lst,lst1;
  for(int i = 0 ; i < 10 ; ++i) lst.push_back(i);
  for(int i = 0 ; i < 10 ; ++i) lst1.push_back(100-i);
  lst.print();
  lst.pop_back();
  lst.pop_front();
  lst.del_node(lst.find_node(4));
  lst.print();
  lst.push_back(111);
  lst.push_front(-1);
  lst.print();
  lst1.print();
  lst.list_concat(&lst1);
  lst.print();
  lst1.print();
  return 0;
}
