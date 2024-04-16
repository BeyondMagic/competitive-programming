/**
	*	author:		beyondmagic
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

//  56 = 2³ * 7¹
// 950 = 2¹ * 5² * 19¹

int main ()
{
	fast_io();

	auto n = read<long long>();

	vector<long long> V(n);
	for (auto &v : V)
		cin >> v;

	long long t1 = (n * (n - 2) * (n + 1)) / 6;

	long long t2 = 0;
	for (int i = 0; i < n - 1; ++i)
		t2 += V[i] * V[i + 1];

	long long t3 = (n * (n - 2) * (n + 1)) / 6;

	print << t1 + t2 + t3 << endl;
}
