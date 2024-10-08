/**
	*	author:		PauloL76, beyondmagic
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
 * Read pair of perhaps different somethings from standard input and return it.
 */
template<
	typename T,
	typename K
>
inline auto
read ()
-> pair<T, K>
{
	pair<T, K> P;
	cin >> P.first >> P.second;
	return P;
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
	auto N = read<long long>();
	auto S = read<long long>();
	auto D = read<long long>();

	// vector<pair<long long, long long>> spells(N);
	// for (auto &[a, b] : spells)
	for (auto a = 0ll, b = 0ll; cin >> a >> b;)
		if (a < S and b > D)
			return print << "Yes" << endl, 0;

	// while (N--)
	// {
	// 	auto [a,b] = read<long long, long long>();
	// 	spells.emplace_back(make_pair(a, b));
	// }

	// for (auto [a, b ] : spells)
	// 	if (a < S and b > D)
	// 		return print << "Yes" << endl, 0;

	// for (long long i = 0; i < N; ++i)		
	// 	if (spells[i].first < S and spells[i].second > D)
	// 		return print << "Yes" << endl,0;

	print << "No" << endl;
}	
