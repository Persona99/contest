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

	void Recalc () {
		counter = ((!left) ? 0 : left->counter)
			+ ((!right) ? 0 : right->counter) + 1;
	}
};

struct Treap {

	Treap () : root (NULL) {}

	void merge ( Node* L, Node* R, Node*& root ) {
		if (L == NULL) {
			root = R;
			return;
		} else if (R == NULL) {
			root = L;
			return;
		}

		else if (L->y > R->y) {
			root = L;
			merge ( L->right, R, root->right );
		} else {
			root = R;
			merge ( L, R->left, root->left );
		}
		root->Recalc ();
	}

	void split ( int idx, Node*& L, Node*& R, Node* root ) {
		int size_left = (root->left) ? root->left->counter + 1 : 1;
		if (size_left <= idx) {
			L = root;
			if (root->right)
				split ( idx - size_left, root->right, R, root->right );
			else R = NULL;

			root->Recalc ();
		} else {
			R = root;
			if (root->left)
				split ( idx, L, root->left, root->left );
			else L = NULL;

			root->Recalc ();
		}
	}

	void pushBack ( int x ) {
		int y = std::rand ();
		if (!root) root = new Node ( x, y );
		else merge ( root, new Node ( x, y ), root );
	}

	void replace ( int start, int end ) {
		end -= --start;

		Treap middle, right;
		split ( start, root, middle.root, root );
		split ( end, middle.root, right.root, middle.root );
		merge ( root, right.root, root );
		merge ( middle.root, root, root );
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

	int n, m; cin >> n >> m;
	Treap treap;
	for (int i = 1; i <= n; i++)
		treap.pushBack ( i );
	int begin, end;
	for (int i = 0; i < m; i++) {
		cin >> begin >> end;
		treap.replace ( begin, end );
		cout << endl;
	}

	treap.inorderTraversal (treap.root);
}