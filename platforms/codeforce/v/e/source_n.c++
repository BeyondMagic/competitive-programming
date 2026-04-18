#include "library.hpp"

using namespace std;

#define even(A) A & 1
#define odd(A) not (A & 1)

long long n, X, y, d;

int main ()
{
	auto t = read<long long>();
	while (t--)
	{
		cin >> n >> X >> y >> d;
		if(abs(y-X) % d != 0 and (y-1)%d != 0 and (n-y)%d!=0 and abs(X-y) % d != 0)
		{
			cout << -1 << endl;
			continue;
		}

		long long ans = min(((X/d) + y/d), (((n-X)/d) + (n-y)/d));

		cout << ans << endl;
	}
}
