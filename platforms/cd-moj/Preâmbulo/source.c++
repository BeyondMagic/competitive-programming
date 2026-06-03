#include "library.hpp"

using namespace std;

int main()
{
	fast_io();
	char c;
	int k = 0;
	stack<char> S;
	while (cin >> c)
		if (c == '*' or c == '/' or c == '_')
		{
			if (S.empty())
				S.emplace(c);
			else
			{
				if (S.top() == c)
					S.pop();
				else
					S.emplace(c);
			}
		}
	cout << (S.empty() ? 'C' : 'E') << endl;
}
