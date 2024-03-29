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

set<int> dec_bin;
static constexpr
auto calculate(const int max = 6) -> void
{
	auto l = 0;
	for (int i = 2; l <= max; ++i)
	{
		auto bin = bitset<32>(i);
		// 0...010
		auto s = bin.to_string();

		l = s.length() - s.find('1');

		dec_bin.insert(stoi(s));
	}
}

int main ()
{
	calculate();
	debug(dec_bin);

	fast_io();

	auto T = read<int>();

	while (T--)
	{
		auto X = read<int>();

		if (X == 1 or dec_bin.contains(X))
		{
			print << "YES" << endl;
			continue;
		}

		for (auto it = begin(dec_bin); it != end(dec_bin);)
		{
			auto e = *it;

			if (e > X * 10)
				break;

			else if (not (X % e))
			{
				X /= e;
				it = begin(dec_bin);
			} else {
				it = next(it);
			}
		}

		if (X == 1 or dec_bin.contains(X))
			print << "YES";
		else
			print << "NO";

		print << endl;
	}
}
