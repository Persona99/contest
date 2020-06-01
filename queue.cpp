#include <iostream>

using namespace std;

struct node{
  int data;
  node* next = NULL;
};

struct queue{
  node *head = NULL;

  void push(int n){
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

  void pop(){
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

  void front(){
    if (head == NULL){
      cout << "error" << endl;
    }
    else{
      cout << head -> data << endl;
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