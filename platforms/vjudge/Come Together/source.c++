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

auto solve ()
{
	auto A = read<long long, long long>(),
		 B = read<long long, long long>(),
		 C = read<long long, long long>();

	B = make_pair(B.first - A.first, B.second - A.second);
	C = make_pair(C.first - A.first, C.second - A.second);

	auto Q = 1ll;

	// On Y-axis.
	if (not B.first and not C.first and B.second and C.second)
	{
		if ((B.second >= 0 and C.second >= 0) or (B.second <= 0 and C.second <= 0))
			Q += min(abs(B.second), abs(C.second));
	}

	// On X-axis.
	if (not B.second and not C.second and B.first and C.first)
	{
		if ((B.first >= 0 and C.first >= 0) or (B.first <= 0 and C.first <= 0))
			Q += min(abs(B.first), abs(C.first));
	}

	// One point on Y-axis and the other in a quadrant.
	if ((not B.first and C.first) or (not C.first and B.first))
		Q += min(abs(B.second), abs(B.second));

	// One point on X-axis and the other in a quadrant.
	if ((not B.second and C.second) or (not C.second and B.second))
		Q += min(abs(B.first), abs(B.first));

	if (
		// First quadrant.
		(B.first > 0 and B.second > 0 and C.first > 0 and C.second > 0) or
		// Second quadrant.
		(B.first < 0 and B.second > 0 and C.first < 0 and C.second > 0) or
		// Third quadrant.
		(B.first < 0 and B.second < 0 and C.first < 0 and C.second < 0) or
		// Fourth quadrant.
		(B.first > 0 and B.second < 0 and C.first > 0 and C.second < 0)
	)
		Q += min(abs(B.first), abs(C.first)) + min(abs(B.second), abs(C.second));

	// Across vertical axes.
	auto across_y = (B.first > 0 and C.first < 0) or (B.first < 0 and C.first > 0);

	// Across horizontal axes.
	auto across_x = (B.second > 0 and C.second < 0) or (B.second < 0 and C.second > 0);

	if (across_x and across_y)
		Q += 0;

	else if (across_x)
		Q += min(B.first, C.first);

	else if (across_y)
		Q += min(B.second, C.second);

	// Should not get here.
	return Q;
}

int main ()
{
	fast_io();

	auto T = read<int>();
	
	while (T--)
		print << solve() << endl;
}
