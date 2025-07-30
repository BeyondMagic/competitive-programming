#include "library.hpp"

using namespace std;

int main ()
{
	auto n = read<size_t>();
	auto sum_first = (n * (n + 1ll)) / 2ll;
	if (sum_first & 1)
		return cout << "NO" << endl, 0;

	auto target_sum = sum_first / 2;
	
	vector<size_t> A, B;
	auto a_sum = 0uz;
	auto b_sum = 0uz;

	cout << "YES" << endl;

	for (auto i = n; i >= 1; --i)
	{
		if (i <= target_sum)
			A.emplace_back(i),
			target_sum -= i;
		else
			B.emplace_back(i);
	}

	auto a_size = A.size();
	cout << a_size << endl;
	for (auto i = 0uz; i < a_size; ++i)
		cout << A[i] << (i + 1 == a_size ? endl : space);

	auto b_size = B.size();
	cout << b_size << endl;
	for (auto i = 0uz; i < b_size; ++i)
		cout << B[i] << (i + 1 == b_size ? endl : space);
	
}
