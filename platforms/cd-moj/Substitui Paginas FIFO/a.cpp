#include <bits/stdc++.h>

#ifdef LOCAL
	#include <debug.hpp>
#else
	#define debug(...)
#endif

using namespace std;

constexpr auto &print = cout;

/* Make code more humane. */
#define endl '\n'
#define space ' '
#define mod %
#define bits_and &
#define bits_or |
#define bits_not ~
#define bits_xor ^
#define bits_shift_right >>
#define bits_shift_left <<

/* Disconnect C. */
inline auto
fast_io (void)
-> void {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
}

/*
 * Read number or string from standard input and return it.
 */
template<
	typename T,
	enable_if_t<(is_arithmetic<T>::value or is_same_v<T, string>), bool> = true
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
 * Read tuple of (possible) diferent types from standard input and return it.
 */
template<
	typename... types,
	enable_if_t<(sizeof...(types) > 1), bool> = true
>
inline auto
read ()
-> tuple<types...>
{
	auto some_function = [](auto&& x)
	{
		cin >> x;
	};

	tuple<types...> T;
	apply(
		[&](auto &...x) {
			(..., some_function(x));
		}, T
	);

	return T;
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


using namespace std;

int main ()
{
	auto [q, pages, pickpage] = read<int, int, int>();

	deque<int> D;
	D.emplace_back(pickpage);

	int page_faults = 1;
	--pages;

	while (pages)
	{
		cin >> pickpage;

		if (find(begin(D), end(D), pickpage) == D.end())
		{
			if (int(D.size()) != q)
				D.emplace_back(pickpage);
			else {
				D.pop_front();
				D.emplace_back(pickpage);
			}
			++page_faults;
		}
		--pages;
	}
	print << page_faults << endl;
}
