#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	scanf("%*d\n");
	char x;
	int64_t n = 0;
	while (scanf(" %*c%c%*c", &x) != EOF)
		if (x == '+')
			++n;
		else
			--n;
	cout << n << endl;
}
