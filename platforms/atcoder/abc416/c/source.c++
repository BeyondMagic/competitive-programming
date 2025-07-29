#include "library.hpp"

using namespace std;

// the amount of strings is
int n;

// Length of each string is
int k;

// position of the string from the lexocgraphical order
int x;

// given strings
vector<string> choices;

// generated strings
vector<string> results;

void generate(
	int depth,
	const string& current_str
)
{
	if (depth == k)
	{
		results.emplace_back(current_str);
		return;
	}

	for (const auto& choice: choices)
	{
		generate(depth + 1, current_str + choice);
	}
}

int main ()
{

	cin >> n >> k >> x;
	choices.resize(n);
	for (auto &s : choices)
		cin >> s;

	generate(0, "");

	sort(begin(results), end(results));

	print << results[x - 1] << endl;
}
