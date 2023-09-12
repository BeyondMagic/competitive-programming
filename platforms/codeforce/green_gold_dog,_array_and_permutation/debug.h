#include <bits/stdc++.h>
#include <atcoder/all>

using namespace std;

#define repeat(i, s, e) for (size_t i = size_t(s); i < size_t(e); ++i)

const size_t INF   = 1LL << 60;
const size_t MOD_1 = 998244353;
const size_t MOD_2 = 998244353;

template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr <<*it << " = " << a << ",  ";
	err(++it, args...);
	cout << endl;
}
