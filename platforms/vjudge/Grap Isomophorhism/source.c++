#include "library.hpp"

using namespace std;

int main ()
{
	vector<int> A = {
		1, 2, 3, 4, 5
	};
	do {
		debug(A);
	} while (next_permutation(begin(A), end(A)));
}
