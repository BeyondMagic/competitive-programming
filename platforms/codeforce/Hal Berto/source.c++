#include "library.hpp"

using namespace std;

#define MAX 1000

vector<int> P{2, 3};

bitset<MAX + 1> V;

int main()
{
	fast_io();
	auto t = read<int>();

	for (auto i = 5, step = 2; i <= MAX; i += step, step = 6 - step)
	{
		if (not V[i])
		{
			V[i] = true;
			P.emplace_back(i);
			for (auto j = i * i; j <= MAX; j += i)
				V[j] = true;
		}
	}

	debug(P.size());

	while (t--)
	{
		auto [b, n] = read<int, int>();
		vector<int> A(MAX, 0);

		int T1 = 0;
		for (auto &p : P)
		{
			int k = 0;
			while (n mod p == 0)
				n /= p,
				++k;

			if (k)
				A.at(p) = k;

			if (++T1 == b)
				break;

		}

		if (n != 1)
		{
			cout << "Nao" << endl;
			continue;
		}

		cout << "Sim" << endl;

		int T2 = 0;
		vector<int> ANS;
		for (auto &p : P)
		{
			ANS.emplace_back(A.at(p));
			if (++T2 == b)
				break;
		}

		cout << ANS << endl;
	}
}
