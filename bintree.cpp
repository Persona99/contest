#include <iostream>
using namespace std;

struct node{
  int value;
  int count = 1;
  node *right = NULL;
  node *left = NULL;
};

struct tree{
  node *head = NULL;
  int count = 0;
  int deep = 0, dmax = 0;
  
  void add(int value){
    deep = 0;
    if (head == NULL){
      dmax = 1;
      head = new node;
      head -> value = value;
      count++;
      return;
    }
    node *tmp = head;
    while (tmp -> right != NULL or tmp -> left != NULL){
      deep++;
      if (tmp -> value > value){
        if (tmp -> left != NULL){
          tmp = tmp -> left;
        }
        else{
          if (deep > dmax) dmax = deep;
          node *left = new node;
          left -> value = value;
          tmp -> left = left;
          count++;
          return;
        }
      }
      else if (tmp -> value < value){
        if (tmp -> right != NULL){
          tmp = tmp -> right;
        }
        else{
          if (deep > dmax) dmax = deep;
          node *right = new node;
          right -> value = value;
          tmp -> right = right;
          count++;
          return;
        }
      }
      else{
        tmp -> count++;
        return;
      }
    }
    deep++;
    if (tmp -> value > value){
      deep++;
      if (deep > dmax) dmax = deep;
      node *left = new node;
      left -> value = value;
      tmp -> left = left;
    }
    else if (tmp -> value < value){
      deep++;
      if (deep > dmax) dmax = deep;
      node *right = new node;
      right -> value = value;
      tmp -> right = right;
    }
     else{
        tmp -> count++;
        return;
      }
    count++;
  }

  void print(node *pnext){
    if (pnext -> left != NULL){
      print(pnext -> left);
    }
    cout << pnext -> value << " " << pnext -> count << endl;
    if (pnext -> right != NULL){
      print(pnext -> right);
    }
  }

  void print_list(node *pnext){
    if (pnext -> left != NULL){
      print_list(pnext -> left);
    }
    if (pnext -> right != NULL){
      print_list(pnext -> right);
    }
    if (pnext -> left == NULL && pnext -> right == NULL)
      cout << pnext -> value << endl;
  }

  void print_branch(node *pnext){
    if (pnext -> left != NULL){
      print_branch(pnext -> left);
    }
    if (pnext -> left != NULL && pnext -> right != NULL)
      cout << pnext -> value << endl;
    if (pnext -> right != NULL){
      print_branch(pnext -> right);
    }
  }

  void print_oneside(node *pnext){
    if (pnext -> left != NULL){
      print_oneside(pnext -> left);
    }
    if (pnext -> left != NULL xor pnext -> right != NULL)
      cout << pnext -> value << endl;
    if (pnext -> right != NULL){
      print_oneside(pnext -> right);
    }
  } 

  void balance(){
    if (isBalanced(head)){
      cout << "YES" << endl;
    }
    else{
      cout << "NO" << endl;
    }
  }

  bool isBalanced(node* tmp){
    int ldeep;
    int rdeep;
    if (tmp == NULL)
        return 1;
    ldeep = height(tmp->left);
    rdeep = height(tmp->right);
    if (abs(ldeep - rdeep) <= 1 && isBalanced(tmp->left) && isBalanced(tmp->right))
        return 1;
    return 0;
  }

  int height(node* tmp){
      if (tmp == NULL)
          return 0;
      return 1 + max(height(tmp->left),height(tmp->right));
  }
};

int main() {
  tree n;
  int tmp;
  cin >> tmp;
  while (tmp != 0){
    n.add(tmp);
    cin >> tmp;
  }
  n.print(n.head);
}