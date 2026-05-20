#include "library.hpp"

using namespace std;

#define MAX 100000

array<long long, MAX + 1>
	spf{},
	exp_a{},
	lim{};

void primes (long long N)
{
	for (long long i = 2; i <= N; ++i)
		if (not spf[i]) {
			spf[i] = i;
			lim[i] = int(log(10.0) / log(float(i)) * 5.0);
			for (long long j = i * 2; j <= N; j += i)
				if (not spf[j])
					spf[j] = i;
		}
}

set<long long> P;

int main()
{
	primes(MAX);
	fast_io();
	auto q = read<long long>();

	for (long long t, x; q--;)
	{
		cin >> t >> x;
		if (t == 1)
			for (long long p, k; x > 1; k = 0)
			{
				k = 0;
				p = spf[x];
				do {
					x /= p;
					++k;
				} while (x mod p == 0);

				exp_a[p] += k;

				if (k and exp_a[p] <= lim[p])
					P.emplace(p);
			}
		else if (t == 2)
		{
			vector<long long> E;
			for (auto &p : P)
			{
				exp_a[p] *= x;
				if (exp_a[p] > lim[p])
					exp_a[p] = lim[p],
					E.emplace_back(p);
			}

			for (auto &e : E)
				P.erase(e);
		}
		else {
			auto ok = true;

			for (long long p, k; x > 1; k = 0)
			{
				k = 0;
				p = spf[x];
				do {
					x /= p;
					++k;
				} while (x mod p == 0);

				if (exp_a[p] < k)
				{
					ok = false;
					break;
				}
			}

			cout << (ok ? "Yes" : "No") << endl;
		}
	}
}
