/**
	*	author:		beyondmagic, paulo76
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

int main ()
{
	fast_io();
	read<int>();
	int m_1 = -1, mi_1 = -1,
		m_2 = -1, mi_2 = -1;
	for (int a, i = 1; cin >> a; ++i)
		if (a > m_1)
		{
			mi_2 = mi_1;
			m_2 = m_1;

			mi_1 = i;
			m_1 = a;
		}
		else if (a > m_2)
		{
			mi_2 = i;
			m_2 = a;
		}

	print << mi_2 << endl;
		
		

	// vector<int> values;
	// while(N--) {
	// 	auto aux = read<int>();
	// 	values.emplace_back(aux);
	// }

	// auto it = ranges::max_element(values);
	// pair<int,int> secondMax = {0,0};
	// for(int i = 0; i < (int)values.size(); ++i) {
	// 	if(values[i] > secondMax.first and values[i] != *it) {
	// 		secondMax.first = values[i];
	// 		secondMax.second = i;
	// 	}
	// 			
	// }

	// print << secondMax.second+1 << endl;
}
