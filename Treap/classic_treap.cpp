#include <iostream>

struct Node {
	Node ( int x, int y, Node* parent = NULL,
		Node* left = NULL, Node* right = NULL ) : counter ( 1 ),
		x ( x ), y ( y ), left ( left ), right ( right ) {};

	int x;
	int y;
	int counter;
	Node* left;
	Node* right;

};

struct Treap {

	Treap () : root (NULL) {}

	void merge ( Node* L, Node* R, Node*& root ) {
		if (L == NULL)
			root = R;
		else if (R == NULL)
			root = L;

		else if (L->y > R->y) {
			root = L;
			merge ( L->right, R, root->right );
		} else {
			root = R;
			merge ( L, R->left, root->left );
		}
	}

	void split ( int x, Node*& L, Node*& R, Node* root ) {
		if (root == NULL) {
			R = NULL;
			L = NULL;
			return;
		}
		
		if (root->x < x) {
			L = root;
			split ( x, root->right, R, root->right );
		} else {
			R = root;
			split ( x, L, root->left, root->left );
		}
	}

	int next ( int x ) {
		auto curr = root;
		int min = root->x >= x ? root->x : (int)1e9 + 1;
		while (curr != nullptr) {
			if (curr->x < min && curr->x >= x) min = curr->x;
			if (curr->x > x) curr = curr->left;
			else if (curr->x == x) {
				min = x;
				break;
			} else curr = curr->right;
		}
		return min == 1e9 + 1 ? -1 : min;
	}

	void add ( int x ) {
		if (root == NULL)
			root = new Node ( x, std::rand () );
		else {
			Node* L = NULL, * R = NULL, * el = new Node ( x, std::rand () );
			split ( x, L, R, root );
			if (check ( x )) return;
			merge ( L, el, L );
			merge ( L, R, root );
		}
	}

	bool check ( int x ) {
		Node* curr = root;
		while (curr != NULL) {
			if (curr->x > x) curr = curr->left;
			else if (curr->x < x) curr = curr->right;
			else return true;
		}
		return false;
	}

	void inorderTraversal (Node* node) const {
		if (node != NULL) {
			inorderTraversal ( node->left );
			std::cout << node->x << ' ';
			inorderTraversal ( node->right );
		}
	}

	Node* root;
};

int main () { 
	using namespace std;

	int n, el, lastr; cin >> n;
	char cmd; bool flag = false;
	Treap treap;
	for (int i = 0; i < n; i++) {
		cin >> cmd;
		if (cmd == '?') {
			cin >> el;
			lastr = treap.next ( el );
			cout << lastr << endl;
			flag = true;
		} else {
			cin >> el;
			if (flag) treap.add ( (el + lastr) % (int) 1e9 );
			else treap.add ( el );
			flag = false;
		}
	}
}