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

#define MAX 10000

int main ()
{
	fast_io();
	
	auto N = read<int>();
	vector<int> A(N), B(N);

	auto min_a = MAX,
		 min_b = MAX;

	auto min_ai = 0, min_bi = 0;

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i] >> B[i];

		// save the second minimum element of both.
		if (A[i] < min_a)
			min_a = A[i],
			min_ai = i;

		// save the second minimum element of both.
		if (B[i] < min_b)
			min_b = B[i],
			min_bi = i;
	}

	auto B_less = B;
	B_less[min_ai] = MAX;

	auto A_less = A;
	A_less[min_bi] = MAX;

	print << min(
			min_a + B[min_ai],
			min(
				min_b + A[min_bi],
				min(
					max(min_a, *ranges::min_element(B_less)),
					max(*ranges::min_element(A_less), min_b)
				)
			)
	)
	<< endl;
}
