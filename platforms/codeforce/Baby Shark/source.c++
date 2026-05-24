#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto s = string{};
	getline(cin, s);
	for (auto i = 1; i <= 3; ++i)
		cout << s << ", doo-doo-doo-doo-doo-doo" << endl;
	cout << s << "!" << endl;
}
