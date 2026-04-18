#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, x, y] = read<long long, long long, long long>();
	auto S = read<string>();

	reverse(begin(S), end(S));

	// basically
	// the righest digits must be the remainder we want
	// there are must be enough zeroes on the left of this number on the string that we can get 0, so that the remainder is not 

	// so basically the perfect string is an ______XXXX1YY
	// we just have to check how many different are there

	auto d = 0;

	for (auto i = 0; i < x; ++i)
	{
		auto c = S[i];

		if (i == y) {
			if (c != '1')
				++d;
		}
		else if (c != '0')
		{
			++d;
		}
	}

	cout << d << endl;
}
