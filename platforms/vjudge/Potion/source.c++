/**
	*	author:		beyondmagic, mathbergsant
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define space ' '
#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

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

int main ()
{
	fast_io();

	auto N = read<unsigned long long>();
	auto X = read<unsigned long long>();

	vector<unsigned long long> A(N);
	for (auto &a : A)
		a = read<unsigned long long>();
	
	ranges::sort(A);

	vector<bool> bitmask(N, true);

	for (auto i = 0ull, K = N; i <= N and K > 0ull; ++i, --K)
	{
		auto combination = bitmask;

		for (auto j = 0ull; j < i; ++j)
			combination[j] = false;

		set<unsigned long long> group;

		do {
			auto sum = 0ull;

			for (auto j = 0ull; j < N; ++j)
				if (combination[j])
					sum += A[j];

			group.insert(sum);

		} while (next_permutation(begin(combination), end(combination)));

		for (auto it = rbegin(group); it != rend(group); ++it)
			if (not ((X - *it) mod K))
				return print << (X - *it) / K << endl, 0;
	}
}
