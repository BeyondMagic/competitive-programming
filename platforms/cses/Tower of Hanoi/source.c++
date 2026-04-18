#include "library.hpp"

using namespace std;

/*
 * The Tower of Hanoi game consists of three stacks (left, middle and right) and n round disks of different sizes. Initially, the left stack has all the disks, in increasing order of size from top to bottom.
 * The goal is to move all the disks to the right stack using the middle stack. On each move you can move the uppermost disk from a stack to another stack. In addition, it is not allowed to place a larger disk on a smaller disk.
* Your task is to find a solution that minimizes the number of moves.
 */

vector<pair<char, char>> moves;

void hanoi(int n, char from, char to, char aux) {
	if (n == 1)
	{
		moves.emplace_back(from, to);
		return;
	}
	hanoi(n - 1, from, aux, to);
	moves.emplace_back(from, to);
	hanoi(n - 1, aux, to, from);
}

int main ()
{
	auto n = read<int>();

	hanoi(n, '1', '3', '2');

	cout << moves.size() << endl;
	for (auto [from, to] : moves)
		cout << from << " " << to << endl;
}
