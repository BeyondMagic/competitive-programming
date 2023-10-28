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

#define ACTIVE '1'
#define EMPTY '0'

vector<int> players;
vector<string> bolt;
int C;
int y = -1; // começa antes de entrar

// move right, right, right until we can slide down
bool move_right()
{
	for (int r = 1; r <= C; ++r)
	{
		bool ok = true;
		for (auto &player : players)
		{
			player = (player + 1) % C;
			if (bolt[y + 1][player] == ACTIVE)
				ok = false;
		}

		// um dos players não conseguiu se mover para baixo
		if (not ok)
			continue;

		return ++y, true;
	}
	return false;
}

// left    -> position == 0 ? C - 1 : position - 1
// right   -> position % C
// flipped -> reverse()
// up      -> y + 1
// down    -> y - 1
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int R;
	cin >> R >> C;

	string nut;
	cin >> nut;

	for (int i = 0; i < nut.length(); ++i)
		if (nut[i] == ACTIVE)
			players.emplace_back(i);
	debug(players);

	bolt.reserve(R);
	for (auto &line : bolt)
		cin >> line;

	while (y + 1 != R)
	{
		if (move_right())
			continue;

		// flips
		ranges::reverse(players);

		if (move_right())
			continue;

		return puts("N"), 0;
	}
	puts("Y");
}
