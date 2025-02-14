#include "library.hpp"

using namespace std;

int main ()
{
	int n;
	cin >> n;
	map<string, long long> S;
	for (string s; n--;)
	{
		cin >> s;
		sort(begin(s), end(s));
		++S[s];
	}

	long long ans = 0;

	for (auto &[_, k] : S)
		ans += k * (k - 1) / 2;

	print << ans << endl;
}
