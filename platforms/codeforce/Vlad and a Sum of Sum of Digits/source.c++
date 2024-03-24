/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define space ' '

static constexpr auto &print = cout;

inline auto
fast_io (void)
-> void {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

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
 * Read string from standard input and return it.
 */
template<
	typename T,
	enable_if_t<is_same_v<T, string>, bool> = true
>
inline auto
read ()
-> T
{
	T str;
	cin >> str;
	return str;
}

/*
 * Print a vector of key data structures separated by a character and ended by a special character.
 */
template<
	typename T
>
ostream& operator<<(ostream& out, const vector<T>& vec)
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	for (auto it = vec.begin(); it < vec_end; ++it)
		out << *it << (it == before ? endl : space);

	return out;
}

#define LIMIT 2 * size_t(1e5) + 10

constexpr auto sum_digits (int x) -> int
{
	int t = 0;

	while (x)
		t += x % 10,
		x /= 10;

	return t;
}

array<int, LIMIT> dp;
constexpr auto sum_sum_digits (int x) -> int
{
	if (dp[x])
		return dp[x];

	for (int i = x; i >= 1; --i)
		if (dp[i])
		{
			dp[x] += dp[i];
			break;
		} else
			dp[x] += sum_digits(i);

	return dp[x];
}

constexpr auto calculate() -> void
{
	for (size_t i = 1; i <= LIMIT - 10; ++i)
		sum_sum_digits(i);
}

int main ()
{
	calculate();
	fast_io();

	auto T = read<int>();

	while (T--)
	{
		auto N = read<int>();
		print << sum_sum_digits(N) << endl;
	}
}
