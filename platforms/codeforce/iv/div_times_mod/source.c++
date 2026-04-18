#include "library.hpp"

using namespace std;

int main ()
{
	auto [n, k] = read<long long, long long>();
	
	auto x_sol = n * k + 1;

	cout << x_sol << endl;
}
