#include <iostream>
#include <string>

using namespace std;

#define endl '\n'

int main()
{
	string s;
	getline(cin, s);
	for (auto i = 1; i <= 3; ++i)
		cout << s << ", doo-doo-doo-doo-doo-doo\n";
	cout << s << "!\n";
}
