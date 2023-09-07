#include <vector>
#include <iostream>

using namespace std;

#define endl '\n'
int main()
{
	string n1, n2;
	cin >> n1 >> n2;
	for (size_t i = 0; i < n1.length(); ++i)
		if (n1[i] != n2[i])
			putchar('1');
		else
			putchar('0');
	putchar('\n');
}
