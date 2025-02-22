#include "library.hpp"

using namespace std;

#define MAX 10

vector<long long> dp(MAX);

long long factorial (long long k)
{
	if (dp[k])
		return dp[k];

	dp[k] = factorial(k - 1) * k;

	return dp[k];
}

long long n;

map<char, long long> M;

int main ()
{
	dp[0] = 1;
	dp[1] = 1;

	cin >> n;

	char c;
	while (cin >> c)
		++M[c];

	debug(M);

	long long ans = factorial(n);

	for (auto &[_, f] : M)
		ans /= factorial(f);

	--ans;

	cout << ans << endl;
}
