/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define space ' '

static constexpr auto &print = cout;

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

/*
 * Read integer from standard input and return it.
 */
template<
	typename T,
	enable_if_t<is_arithmetic<T>::value, bool> = true
>
inline auto
read ()
-> T
{
	T number;
	cin >> number;
	return number;
}

/*
 * Print a vector of integer separated by a character.
 */
ostream& operator<<(ostream& out, const vector<int>& vec)
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	for (auto it = vec.begin(); it < vec_end; ++it)
		out << *it << (it == before ? endl : space);

	return out;
}

long long process(unordered_map<long long, long long> &dp, long long x)
{
	if (not dp[x])
		dp[x] = process(dp, x / 2) + process(dp, (x + 1) / 2);

	return (dp[x] < 0 ? 0 : dp[x]) + x;
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<long long, long long> dp;
	dp[0] = -1;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 2;

	const auto N = read<long long>();
	print << process(dp, N) << endl;
}
