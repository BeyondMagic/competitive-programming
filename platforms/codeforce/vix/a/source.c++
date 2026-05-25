#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	auto t = read<int>();
	int n;
	string A, B, ans;
	while (t--)
	{
		cin >> n;
		cin >> A >> B;

		int sa = 0, sb = 0;

		for (int i = 0; i < n; ++i)
			if (A[i] > B[i])
				++sa;
			else if (B[i] > A[i])
				++sb;

		if (sa == sb)
			ans = "EQUAL";
		else if (sa > sb)
			ans = "RED";
		else
			ans = "BLUE";
		cout << ans << endl;
	}
}
