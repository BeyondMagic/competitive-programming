#include <iostream>
#include <vector>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	vector<bool> passed(n, false);

	{
		size_t n2, l;
		while (cin >> n2)
			while (n2--)
			{
				cin >> l;
				passed[l - 1] = true;
			}
	}
		
	for (const auto l : passed)
		if (not l)
			return puts("Oh, my keyboard!"), 0;
	puts("I become the guy.");

}
