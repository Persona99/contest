#include <iostream>

using namespace std;

class DSU {
public:

	DSU ( unsigned int len ) : parents ( new int[len] {0} ) {};

	void makeSet ( int el ) {
		parents[el] = el;
	}

	int find ( int x ) {
		if (parents[x] == x) return x;
		else return parents[x] = find (parents[x]);
	}

	bool unite ( int x, int y ) {
		x = find ( x );
		y = find ( y );
		if (x == y) return false;
		if (rand () % 2) parents[x] = y;
		else parents[y] = x;
		parents[x] = y;
		return true;
	}

	int* parents;
};

int main () {

	int n, m, a, b, k = -1;
	cin >> n >> m;

	DSU dsu ( n );
	for (int i = 0; i < n; i++)
		dsu.parents[i] = i;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		a--;
		b--;
		if (dsu.unite ( a, b )) {
			k = i;
		}
	}

	cout << k + 1;
}