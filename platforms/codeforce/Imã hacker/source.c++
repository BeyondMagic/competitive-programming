#include "library.hpp"

using namespace std;

auto solvel (const int n, string &A, string &B)
{
	for (int i = 0; i < n; ++i)
	{
		if (i + 1 == n)
			break;
 
		if (A[i] == B[i] and A[i + 1] == B[i + 1])
			continue;
 
		if (B[i] == B[i + 1])
			A[i] = B[i],
			A[i + 1] = B[i];
 
		else
		{
			if (A[i] == B[i])
				continue;

			else {
				A[i] = B[i];
				A[i + 1] = B[i];
				continue;
			}
		}
	}

	auto ok = true;
	for (auto i = 0; i < n and ok; ++i)
		ok = A[i] == B[i];

	return ok;
}

auto solver (const int n, string &A, string &B)
{
	for (int i = n - 1; i > 0; --i)
	{
		if (i - 1 == -1)
			break;

		if (A[i] == B[i] and A[i - 1] == B[i - 1])
			continue;
 
		if (B[i] == B[i - 1])
			A[i] = B[i],
			A[i - 1] = B[i];
 
		else
		{
			if (A[i] == B[i])
				continue;

			else {
				A[i] = B[i];
				A[i - 1] = B[i];
				continue;
			}
		}
	}

	auto ok = true;
	for (auto i = 0; i < n and ok; ++i)
		ok = A[i] == B[i];

	return ok;
}

int main()
{
	fast_io();
	auto n = read<int>();
	auto [A, B] = read<string, string>();
	auto ok = solvel(n, A, B) or solver(n, A, B);
	cout << (ok ? "YES" : "NO") << endl;
}
