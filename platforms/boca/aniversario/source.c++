#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	size_t n;
	cin >> n;
	vector<pair<size_t, string>> people(n);
	while (n--)
		cin >> people[n].second >> people[n].first;
	
	for (size_t i = 0; people.size() >= 2; ++i) // if we have at least 2 people
	{
		for (auto &person : people)
		{
			for (const auto &other : people)
			{
				auto person_age = to_string(person.first);
				auto other_reversed = to_string(other.first);
				if (other_reversed == person_age)
					cout << "Em " << i << " anos " << person.second << " faz " << person.first << " e " << other.second << ' ' << other_reversed << endl;
				reverse(begin(other_reversed), end(other_reversed));
				if (other_reversed == person_age)
					cout << "Em " << i << " anos " << person.second << " faz " << person.first << " e " << other.second << ' ' << other_reversed << endl;
			}
			// add one to everyone's age
			++person.first;
		}
	}
}
