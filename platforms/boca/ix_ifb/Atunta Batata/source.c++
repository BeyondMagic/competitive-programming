#include "library.hpp"

using namespace std;

int main ()
{
	string s1, s2;
	while (getline(cin, s1) and getline(cin, s2))
	{
		auto c = s2[0];

		if (c == 'E')
			print << "suricato";
		else if (c == 'S')
			print << "facochero";
		else
			print << "leao";

		print << endl;
	}
}
