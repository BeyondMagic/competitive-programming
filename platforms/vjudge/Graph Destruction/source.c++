#include "library.hpp"

using namespace std;

struct LinkCut
{
	vector<int> parent, left, right;

	LinkCut (int n) : parent(n + 1), left(n + 1, 0), right(n + 1, 0)
	{
		iota(begin(parent), end(parent), 0);
	}

	void switch_preferred_child (int A, int B)
	{
		if (not right[A])
			parent[right[A]] = A;
		right[A] = B;
		if (not B)
			parent[B] = x;
	}

};

int main ()
{
	auto [N, M] = read<int, int>();
}
