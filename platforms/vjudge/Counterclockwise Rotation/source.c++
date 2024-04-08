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

int main ()
{
	fast_io();
	print << fixed << setprecision(7);

	auto x = read<long double>();
	auto y = read<long double>();
	auto degrees_theta = read<unsigned long long>() mod 360;

	if (not degrees_theta or (not x and not y))
		return print << x << space << y << endl, 0;

	constexpr auto PI = numbers::pi_v<long double>;

	long double hundred_eighty = 180.0f;
	auto rad_theta = (long double)degrees_theta * PI / hundred_eighty;

	auto new_x = x * cos(rad_theta) - y * sin(rad_theta);
	auto new_y = x * sin(rad_theta) + y * cos(rad_theta);

	print << new_x << space << new_y << endl;
}
