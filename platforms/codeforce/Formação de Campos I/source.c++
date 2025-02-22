#include "library.hpp"

using namespace std;

int main ()
{
	char c;
	cin >> c;
	cout << char(toupper(c));
	while (cin >> c)
		cout << char(tolower(c));
	cout << endl;
}
