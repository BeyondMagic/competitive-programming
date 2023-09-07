#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	for (size_t i = 0; i < n; ++i)
	{
		if (i & 1)
			cout << "I love ";
		else
			cout << "I hate ";
		if (i != n - 1)
			cout << "that ";
	}
	puts("it");
}
