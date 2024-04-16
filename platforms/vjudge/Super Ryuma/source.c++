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

int main ()
{
	fast_io();

	auto [r_1, c_1] = read<int, int>();
	auto [x, y] = read<int, int>();

	// normalizar.
	x -= r_1;
	y -= c_1;

	auto Q = 0;

	if (
		abs(x) + abs(y) >= 5 and
		(abs(x) + abs(y)) & 1
	)
	{
			debug("correção de um movimento", x, y);

			Q = 1;
			// qualquer lugar que a gente se mover, estará corrigido
			++x;
	}

	for (auto i = 1; i <= 2; ++i)
	{

		if (not x and not y)
			break;

		// diagonal
		if (x and x == y) {
			debug("diagonal", x, y);

			++Q;
			x -= x;
			y -= y;

		// axis vertical
		} else if (not x and y >= -3 and y <= 3) {
			debug("vertical", x, y);

			++Q;
			y -= y;

		// axis horizontal
		} else if (not y and x >= -3 and x <= 3) {
			debug("horizontal", x, y);

			++Q;
			x -= x;

		// raio
		} else if (x >= -2 and x <= 2 and y >= -2 and y <= 2) {
			debug("raio", x, y);

			++Q;
			x -= x;
			y -= y;

		// correção de um diagonal
		} else {
			debug("corrigir", x, y);

			++Q;

			// horizontal
			if (abs(x) > abs(y))
				x /= 2,
				y = x;

			else
				y /= 2,
				x = y;
		}
	}

	print << Q << endl;
}
