#include "library.hpp"

using namespace std;

// Minha intuição está dizendo que a resposta será alternada.
int main ()
{
	auto N = read<int>();

	if (N == 1)
		return print << 1 << endl, 0;

	vector<int> perm;

	int pr = 0;
	
	for (int s = 1, k = N; s < k; s += 2)
	{
		perm.emplace_back(k - s);

		if (abs((k - s) - pr) == 1)
			return print << "NO SOLUTION" << endl, 0;

		pr = k - s;
	}

	for (int s = 0, k = N; s < k; s += 2, pr = k - s)
	{
		perm.emplace_back(k - s);

		if (abs((k - s) - pr) == 1)
			return print << "NO SOLUTION" << endl, 0;

		pr = k - s;
	}

	for (int i = 0; i < N; ++i)
		print << perm[i] << (i + 1 == N ? endl : space);
}
