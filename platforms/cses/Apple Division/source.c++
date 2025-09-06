#include "library.hpp"

using namespace std;

long long S_min = LONG_LONG_MAX;
vector<long long> P;
long long P_size;
long long P_sum = 0;

void recursive (long long a_sum = 0, long long index = 0)
{
	if (index == P_size)
	{
		long long b_sum = P_sum - a_sum;
		S_min = min(S_min, abs(a_sum - b_sum));
		return;
	}

	recursive(a_sum, index + 1);
	recursive(a_sum + P[index], index + 1);
}

int main ()
{
	auto n = read<long long>();
	P = read<vector<long long>>(n);
	P_size = P.size();
	P_sum = accumulate(begin(P), end(P), 0ll);
	recursive();
	cout << S_min << endl;
}
