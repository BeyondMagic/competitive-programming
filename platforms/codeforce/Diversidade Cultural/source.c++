#include "library.hpp"

using namespace std;

int n;
string s;

map<char, long long> freq;
vector<long long> pre, suf;
char c;

int main ()
{
	cin >> n >> s;
	pre.resize(n);
	suf.resize(n);

	for (long long i = 0, d = 0; i < n; ++i)
	{
		c = s[i];
		if (not freq[c])
			++d;
		++freq[c];
		pre[i] = d;
	}

	freq.clear();

	for (long long i = n - 1, d = 0; i >= 0; --i)
	{
		c = s[i];
		if (not freq[c])
			++d;
		++freq[c];
		suf[i] = d;
	}

	long long k = n + 1;

	for (long long i = 2; i < n; ++i)
		k = min(k, abs(pre[i] - suf[i]));

	print << k << endl;

	debug(pre, suf);
}
