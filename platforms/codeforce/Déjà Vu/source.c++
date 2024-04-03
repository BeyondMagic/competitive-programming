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

bool is_palindrome (string str)
{
	auto n = int(str.length());

	for (int i = 0, j = n - 1; i * 2 < n; ++i, --j)
		if (str[i] != str[j])
			return false;

	return true;
}

int main ()
{
	fast_io();

	auto T = read<int>();

	while (T--)
	{
		auto S = read<string>();

		bool is_as = true;
		for (auto &x : S)
			if (x != 'a')
			{
				is_as = false;
				break;
			}

		if (is_as)
		{
			print << "NO" << endl;
			continue;
		}

		print << "YES" << endl;

		auto l = 'a' + S;
		if (not is_palindrome(l))
		{
			print << l << endl;
			continue;
		}

		auto r = S + 'a';
		print << r << endl;
	}
}
