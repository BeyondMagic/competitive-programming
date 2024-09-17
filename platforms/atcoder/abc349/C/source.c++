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

	vector<int> characters(256, 0);

	auto S = read<string>();
	auto T = read<string>();

	// to uppercase.
	for (auto &c : S)
	{
		c = toupper(c);
		++characters[c];
	}

	auto T_n = 3, Q = 0;

	char first = 0, second = 0;

	// first method
	for (auto i = 0; i < T_n; ++i)
	{
		if (characters[T[i]])
		{
			++Q;

			--characters[T[i]];

			if (not first)
				first = T[i];
			else
				second = T[i];


			// Encontrei três caracteres iguais!
			if (Q >= 3)
				return print << "Yes" << endl, 0;
		}
	}

	// second method
	// encontrei 2 caracteres iguais
	debug(Q);
	debug(first, second);

	if (
			Q == 2 and
			(
				(T[0] == first and T[1] == second and T[2] == 'X') or
				(T[0] == second and T[1] == first and T[2] == 'X')
			)
		)
		return print << "Yes" << endl, 0;
	print << "No" << endl;
}
