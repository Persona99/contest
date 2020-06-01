#include <iostream>

using namespace std;

struct node{
  int data;
  node* next = NULL;
};

struct deck{
  node *head = NULL;
  
  void push_front(int n){
    node *tmp = new node;
    tmp -> data = n;
    tmp -> next = head;
    head = tmp; 
    cout << "ok" << endl;
  }

  void push_back(int n){
    node *tmp = new node;
    tmp -> data = n;
    if (head == NULL){
      head = tmp;
    }
    else{
      node *pnext = head;
      while (pnext -> next != NULL){
        pnext = pnext -> next;
      }
      pnext -> next = tmp;
    }
    cout << "ok" << endl;
  }

  void pop_front(){
    if (head == NULL){
      cout << "error" << endl;
    }
    else if (head -> next == NULL){
      cout << head -> data << endl;
      head = NULL;
    }
    else{
      node *tmp = head -> next;
      cout << head -> data << endl;
      delete head;
      head = tmp;
    }
  }

  void pop_back(){
    if (head == NULL){
      cout << "error" << endl;
    }
    else if (head -> next != NULL){
      node *tmp = head;
      node *tmp1 = NULL;
      while (tmp -> next != NULL){
        tmp1 = tmp;
        tmp = tmp -> next;
      }  
      cout << tmp -> data << endl;
      delete tmp;
      tmp1 -> next = NULL;
    }
    else{
      cout << head -> data << endl;
      head = NULL;
    }
  }
  
  void front(){
    if (head == NULL){
      cout << "error" << endl;
    }
    else{
      cout << head -> data << endl;
    }
  }

  void back(){
    if (head == NULL){
      cout << "error" << endl;
    }
    else{
      node *tmp = head;
      while (tmp -> next != NULL){
        tmp = tmp -> next;
      }
      cout << tmp -> data << endl;
    }
  }

  void size(){
    node *tmp = head;
    if (head == NULL){
      cout << '0' << endl;
    }
    else{
      int count = 0;
      while (tmp -> next != NULL){
        tmp = tmp -> next;
        count++;
      }
      cout << count + 1 << endl;
    }
  }

  void clear(){
    head = NULL;
    cout << "ok" << endl;
  }
};

void exit(){
  cout << "bye" << endl;
}

int main() { 
}