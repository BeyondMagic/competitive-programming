#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;

	for (size_t i = 1; i <= n; ++i)
	{
		const auto s = to_string(i);
		bool l = true;
		for (auto &c : s)
			if (c != '4' and c != '7')
			{
				l = false;
				break;
			}
		if (l and not (n % i))
			return puts("YES"), 0;
	}
	puts("NO");
}
