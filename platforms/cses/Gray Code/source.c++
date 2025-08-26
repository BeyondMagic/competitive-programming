#include "library.hpp"

using namespace std;

/*
* Gray Code
*
* A Gray code is a list of all 2^n bit strings of length n, where any two successive strings differ in exactly one bit (i.e., their Hamming distance is one).
* Your task is to create a Gray code for a given length n.
*/

int main ()
{
	auto n = read<int>();

	for (int i = 0; i < (1 << n); i++)
	{
		auto k = i ^ (i >> 1);
		auto str = bitset<16>(k).to_string().substr(16 - n);
		cout << str << endl;
	}
}
