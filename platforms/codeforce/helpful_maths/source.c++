#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	char c;
	vector<int> numbers;
	do {
		cin >> n;
		numbers.emplace_back(n);
	} while (cin >> c);
	sort(begin(numbers), end(numbers));
	for (auto it = begin(numbers);; ++it)
	{
		cout << *it;
		if (it + 1 == end(numbers))
			break;
		putchar('+');
	}
}
