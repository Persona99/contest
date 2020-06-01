#include <iostream>
#include <ctime>


struct RSU {

	RSU ( size_t size )
		: parents ( new int[size] ) {
		std::srand ( unsigned ( std::time ( 0 ) ) );
	};

	void makeSet ( int el ) {
		parents[el] = el;
	}

	int find ( int el ) {
		if (parents[el] != el) return parents[el] = find ( parents[el] );
		return el;
	}

	bool unite ( int x, int y ) {
		x = find ( x );
		y = find ( y );
		if (x == y) return false;
		if (std::rand () & 1) std::swap ( x, y );
		parents[x] = y;
		return true;
	}

private:
	int* parents;
};

int main () { 
	using namespace std;
	int n, m, counter(0); cin >> n >> m;

	RSU rsu ( n );
	for (int i = 0; i < n; i++)
		rsu.makeSet ( i );
	int a, b;
	while (m-- > 0) {
		cin >> a >> b;
		if (rsu.unite ( a, b )) n--;
		counter++;
	}
	cout << counter;

}