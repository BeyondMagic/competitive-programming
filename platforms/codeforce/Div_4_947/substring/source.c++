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

int main ()
{
	fast_io();

	auto T = read<int>();

	while (T--)
	{
		auto N = read<int>();
		auto S = read<string>();

		auto less_half = 0;

		auto max = N / 2;

		for (int k = 0; k <= max; ++k)
		for (int i = 1; i <= max; ++i)
		{
			auto s_new = S.substr(k, i);

			// fazer a string multiplicando ela até ser igual ou maior que a string original.
			while (s_new.length() < S.length())
				s_new += s_new;

			// se passar do tamanho, ja desiste.
			if (s_new.length() != S.length())
				continue;

			int qnt = 0;
			for (int j = 0; j < N; ++j)
				if (s_new[j] != S[j])
					++qnt;

			if (qnt <= 1)
			{
				less_half = i;
				break;
			}
		}

		if (less_half)
			print << less_half << endl;
		else
			print << N << endl;

		// a gente começa da menor substring possivel, de tamanho 1
		// e crescemos ela até conseguirmos formar uma que seja igual ou diferente a todas as outras substrings de mesmo tamanho no resto da string original

		// se passarmos da metade tamanho
		// só a string inteira derá pra imprimir
		// auto max = N / 2;

		// int less_half = 0;

		// for (int i = 1; i <= max; ++i)
		// {
		// 	string s_new = S.substr(0, i);

		// 	print << "s_new = " << s_new << endl;

		// 	// para as outras substrings...
		// 	int qnt = 0;

		// 	for (int k = 0; k + i - 1 <= max; ++k)
		// 	{
		// 		// substring depois de i
		// 		string s_c = S.substr(i + k + 1, i);

		// 		// quantidade de diferenças nessa string.
		// 		for (int j = 0; j < i; ++j)
		// 			if (s_c[j] != s_new[j])
		// 				++qnt;

		// 		print << ": s_c = " << s_c << " : qnt = " << qnt << endl;
		// 	}

		// 	if (qnt <= 1) {
		// 		less_half = i;
		// 		break;
		// 	} else
		// 		print << "at the end : qnt = " << qnt << endl;
		// }

		// print << "|| VALUE || = ";

		// if (less_half)
		// 	print << less_half << endl;
		// else
		// 	print << N << endl;
			

	}
}
