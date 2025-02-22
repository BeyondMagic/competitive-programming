#include "library.hpp"

using namespace std;

const long long MAX { 20000000 + 10 };

vector<long long> sieve(long long N)
{
	bitset<MAX> sieve;
	vector<long long> ps { 2, 3 };
	sieve.set();

	for (long long i = 5, step = 2; i <= N; i += step, step = 6 - step) {
		if (sieve[i])
		{
			ps.push_back(i);

			for (long long j = i * i; j <= N; j += 2*i)
				sieve[j] = false;
		}
	}

	return ps;
}

//long long tau(long long n)
//{
//	if (dp[n])
//		return dp[n];
//
//	long long res = 0;
//	for (long long d = 1; d * d <= n; ++d)
//    {
//        debug(n, d);
//		if (n % d == 0)
//			res += (d * d == n ? 1 : 2);
//    }
//
//	dp[n] = res;
//
//	return res;
//}

long long tau9s(long long n, vector<long long> &primes)
{
	long long ans = 0;
	for (auto &p : primes)
	{
		if (p * p * p * p * p * p * p * p > n)
			break;
		++ans;
	}

	vector<long long> dp;

	for (auto& p : primes) {
		long long p2 = p * p;
		if (p2 > n)
			break;
		dp.push_back(p2);
	}

	int dp_size = dp.size();
	for (int i = 0; i < dp_size; ++i)
		for (int j = i + 1; j < dp_size; ++j)
		{
			if (dp[i] > n / dp[j])
				break;
			++ans;
		}

    return ans;
}

int main ()
{
	long long n;
	cin >> n;
	auto primes = sieve(sqrt(n));
    //debug(primes);

	print << tau9s(n, primes) << endl;
}
