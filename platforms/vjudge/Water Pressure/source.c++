#include "library.hpp"

using namespace std;

int main ()
{
	auto x = read<float>();
	print << fixed << setprecision(3) << endl;
	print << x / 100 << endl;
}
