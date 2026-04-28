#include "library.hpp"

using namespace std;

int main()
{
	auto [v, t] = read<int, int>();
	auto A = read<vector<int>>(t);

	for (auto &a : A)
	{
		v += a;
		if (v < 0)
			v = 0;
		else if (v > 100)
			v = 100;
	}

	cout << v << endl;
}
