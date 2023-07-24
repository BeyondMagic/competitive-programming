#include <iostream>
#include <tuple>
#include <vector>

#define DBG(vari) cout <<#vari<<" = "<<(vari)<<endl;

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	size_t problems = 0, sure, f;
	while (n--)
	{
		sure = 0;
		for (size_t i = 1; i <= 3; ++i)
		{
			cin >> f;
			if (f == 1)
			{
				++sure;
				if (sure == 2)
					++problems;
			}
		}
	}
	cout << problems << endl;
}
