/**
	*	author:		beyondmagic
	*	sensei:		Edson Alves
**/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
	#include "debug.h"
#else
	#define debug(...)
#endif

#define endl '\n'

template <typename RAIter>
int parallel_sum(RAIter beg, RAIter end)
{
    auto len = end - beg;
    if(len < 1000)
        return std::accumulate(beg, end, 0);

    RAIter mid = beg + len/2;
    auto handle = std::async(std::launch::async,
                              parallel_sum<RAIter>, mid, end);
    int sum = parallel_sum(beg, mid);
    return sum + handle.get();
}

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	size_t n;
	cin >> n;

	std::vector<int> v(n, 1);
	std::cout << "The sum is " << parallel_sum(v.begin(), v.end()) << '\n';
	// std::cout << "The sum is " << accumulate(v.begin(), v.end(), 0) << '\n';
}
