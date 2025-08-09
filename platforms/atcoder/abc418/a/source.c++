#include "library.hpp"

using namespace std;

int main ()
{
	auto N = read<int>();
	auto s = read<string>();

	auto n = s.length();

	if (n < 3)
		return cout << "No" << endl, 0;

	auto last_three_characters = s.substr(n - 3, 3);

	cout << (last_three_characters == "tea" ? "Yes" : "No") << endl;
}
