#include "library.hpp"

using namespace std;

auto modd (int k)
{
	return k < 0 ? k + 'z' : k;
}

int main ()
{
	auto [S, T] = read<string, string>();
	auto n = int(S.length());
	for (int i = 0, dif = -1; i < n; ++i)
		if (dif == -1)
			dif = modd(S[i] - T[i]);
		else if (dif != modd(S[i] - T[i]))
			return print << "No" << endl, 0;

	print << "Yes" << endl;
}
