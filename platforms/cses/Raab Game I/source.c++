#include "library.hpp"
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int solve()
{
	auto [n, a, b] = read<int, int, int>();

	// The total number of wins must not exceed the number of games.
	if (a + b > n)
		return cout << "NO" << endl, 0;

	// An edge case: a player cannot win all n games, because the opponent
	// holds the 'n' card and can force at least one non-loss (a tie or a win).
	// This is only possible if n=1.
	if (a == n || b == n) {
		if (n == 1 && (a == 1 || b == 1))
		{
		}
		else
			return cout << "NO" << endl, 0;
	}

	// A special case: if a+b = n, it means no ties. If a=b=0, all ties.
	// If n=2, a=1, b=1, this is impossible because the only way is (1,2) and (2,1),
	// but the scores would be the same.
	if (n == 2 && a == 1 && b == 1)
		return cout << "NO" << endl, 0;

	vector<int> A, B;
	int tied = n - a - b;

	// Strategy:
	// 1. Ties use the lowest numbers (1...tied)
	// 2. A's wins use mid-low numbers
	// 3. B's wins use high numbers

	// --- Handle Ties ---
	for (int i = 1; i <= tied; ++i)
	{
		A.emplace_back(i);
		B.emplace_back(i);
	}

	// --- Handle A's Wins ---
	int next_card_for_wins = tied + 1;
	for (int i = 0; i < a; ++i) {
		A.emplace_back(next_card_for_wins + 1);
		B.emplace_back(next_card_for_wins);
		next_card_for_wins += 2;
	}

	// --- Handle B's Wins ---
	int next_high_card = n;
	for (int i = 0; i < b; ++i) {
		A.emplace_back(next_high_card - 1);
		B.emplace_back(next_high_card);
		next_high_card -= 2;
	}

	// The number of cards used must be exactly n
	if (int(A.size()) != n)
		return cout << "NO" << endl, 0;

	cout << "YES" << A << endl << B << endl;
}

int main ()
{
	fast_io();
	auto t = read<int>();
	while (t--)
	{
		solve();
	}
	return 0;
}

