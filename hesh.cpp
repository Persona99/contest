#include <iostream>
using namespace std;

struct node{
  string s;
  node *pnext = NULL;
};

long long hash_map(string s){
  const int p = 31;
  long long hash = 0, p_pow = 1;
  for (size_t i = 0; i < s.length(); i++)
  {
    hash += (s[i] - 'a' + 1) * p_pow;
    p_pow *= p;
  }
  return hash;
}

void found(string s, node* arr){
  node *tmp = arr;
  if (tmp == NULL){
    cout << "NO" << endl;
    return;
  }
  while (tmp -> pnext != NULL){
    if (tmp -> s == s){
      cout << "YES" << endl;
      return;
    }
    tmp = tmp -> pnext;
  }
  if (tmp -> s == s){
    cout << "YES" << endl;
    return;
  }
  cout << "NO" << endl;
  return;
}

void del(string s, node *arr){
  node *tmp = arr;
  node *tmp1 = arr;
  if (tmp == NULL){
    return;
  }
  if (tmp -> pnext == NULL){
    delete tmp;
    return;
  }
  while (tmp -> pnext != NULL){
    if (tmp -> s == s){
      tmp1 -> pnext = tmp -> pnext;
      delete tmp;
    }
    else{
      tmp1 = tmp;
      tmp = tmp -> pnext;
    }
  }
}

int main() {
  node* arr[(int)1e6];  
  string plus;
  cin >> plus;
  while (plus != "#"){
    if (plus == "+"){
      cin >> plus;
      if (arr[hash_map(plus) % 10] == NULL){
        arr[hash_map(plus) % 10] = new node;
        arr[hash_map(plus) % 10] -> s = plus;
      }
      else{
        node *tmp = arr[hash_map(plus) % 10];
        while (tmp -> pnext != NULL)
          tmp = tmp -> pnext;
        tmp -> pnext = new node;
        tmp -> pnext -> s = plus;
      }
    }
    else if (plus == "?"){
      cin >> plus;
      found(plus, arr[hash_map(plus) % 10]);
    }
    else {
      cin >> plus;
      del(plus, arr[hash_map(plus) % 10]);
    }
    cin >> plus;
  }
} 