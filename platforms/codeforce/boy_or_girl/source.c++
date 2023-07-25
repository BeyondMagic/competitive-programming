#include <iostream>
#include <set>

using namespace std;

#define endl '\n'

int main()
{
	set<char> name;
	char c;
	while (cin >> c)
		name.emplace(c);
	if (name.size() & 1)
		puts("IGNORE HIM!");
	else
		puts("CHAT WITH HER!");
}
