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
	auto N = read<int>();

	auto max_x = 0,
		 max_y = 0,
		 min_x = 0,
		 min_y = 0;

	for (int x = 0, y = 0; N--;)
	{
		x = read<int>();
		y = read<int>();

		if (x == 0)
		{
			if (y > 0 and y > max_y)
				max_y = y;
			else if (y < min_y)
				min_y = y;
		} else {
			if (x > 0 and x > max_x)
				max_x = x;
			else if (x < min_x)
				min_x = x;
		}
			
	}
	
	debug(max_y, max_y, min_x, min_y);

	auto Q = 2 * abs(max_x) + 2 * abs(max_y) + 2 * abs(min_x) + 2 * abs(min_y);

	return Q;
}

int main ()
{
	fast_io();

	auto T = read<int>();

	while (T--)
		print << solve() << endl;
}
