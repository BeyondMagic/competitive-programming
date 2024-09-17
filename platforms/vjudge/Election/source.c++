#include "library.hpp"

using namespace std;

int main ()
{
	auto N = read<int>();
	map<string, int> m;
	auto maior = -1;
	string nome = "";

	while (N--)
	{
		auto s = read<string>();
		++m[s];

		if (m[s] > maior)
			nome = s,
			maior = m[s];
	}

	print << nome << endl;
}
