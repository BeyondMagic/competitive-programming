/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#define repeat(N) for (auto i = 1; i <= N; ++i)

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
 * Read integer from standard input and return it.
 */
template<
	typename T
>
inline auto
read (const size_t &N)
-> vector<typename T::value_type>
{
	T vec(N);
	for (auto &item : vec)
		cin >> item;
	return vec;
}

/*
 * Print a vector of key data structures separated by a character and ended by a special character.
 */
template<
	typename T
>
ostream& operator<<(ostream &out, const vector<T> &vec)
{
	const auto vec_end = vec.end();
	const auto before = prev(vec_end);

	constexpr auto newline = '\n';
	constexpr auto space = ' ';

	for (auto it = vec.begin(); it < vec_end; ++it)
		out << *it << (it == before ? newline : space);

	return out;
}

int main ()
{
	fast_io();

	auto N = read<long long>();
	auto A = read<vector<long long>>(N * 2);

	vector<long long>
		S(N - 1),
		T(N - 1);

	repeat(N - 1) {
		S[i - 1] = read<long long>();
		T[i - 1] = read<long long>();
	}

	repeat(N - 1) {
		A[i + 1] += A[i] / S[i] * T[i];
	}

	// print << A << '\n';
	// print << S << '\n';
	// print << T << '\n';
}
