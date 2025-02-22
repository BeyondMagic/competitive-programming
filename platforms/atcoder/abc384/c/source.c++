#include "library.hpp"

using namespace std;

struct comp
{
	bool operator()(const pair<int,string>& a, const pair<int,string>& b) const
	{
		if (a.first > b.first)
			return true;
		else if (a.first < b.first)
			return false;
		return lexicographical_compare(begin(a.second), end(a.second), begin(b.second), end(b.second));
	}
};

int main ()
{
	auto [A, B, C, D, E] = read<int, int, int, int, int>();
	vector<int> points = {A, B, C, D, E};
	set<pair<int, string>, comp> ranking;
	vector<string> names = {
		"ABCDE",
		"BCDE",
		"ACDE",
		"ABDE",
		"ABCE",
		"ABCD",
		"CDE",
		"BDE",
		"ADE",
		"BCE",
		"ACE",
		"BCD",
		"ABE",
		"ACD",
		"ABD",
		"ABC",
		"DE",
		"CE",
		"BE",
		"CD",
		"AE",
		"BD",
		"AD",
		"BC",
		"AC",
		"AB",
		"E",
		"D",
		"C",
		"B",
		"A",
	};
	for (auto name : names)
	{
		int p = 0;
		for (auto &c : name)
			p += points[c - 'A'];
		ranking.emplace(make_pair(p, name));
	}

	for (auto &name : ranking)
		print << name.second << endl;
}
