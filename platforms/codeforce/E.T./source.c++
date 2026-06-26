#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto n = read<int>();
	auto s = string();
	auto V = array<int, 5>{0, 0, 0, 0, 0};

	while (cin >> s)
	{
		if (s == "PIP")
			cout << V << endl;
		else
			for (int i = 0; i < 5; ++i)
				if (s[i] == '*')
					++V[i];
	}
}
