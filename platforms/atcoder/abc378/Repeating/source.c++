#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<int>();
	unordered_map<int, int> A;
	for (int k, i = 1; n--; ++i)
	{
		k = read<int>();
		if (not A.contains(k))
		{
			A[k] = i;
			print << -1 << endl;
			continue;
		}

		print << A[k] << endl;
		A[k] = i;
	}
}
