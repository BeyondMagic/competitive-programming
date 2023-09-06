#include <iostream>
#include <iomanip>

using namespace std;

int main ()
{
	size_t l;
	cin >> l;
	char t;
	cin >> t;
	double s = 0;
	double n;
	for (size_t i = 0; i < 12; i++)
		for (size_t j = 0; j < 12; j++)
		{
			cin >> n;
			if (i == l)
				s += n;
		}
	cout << fixed << setprecision(1);
	if (t == 'M')
		s /= 12;
	cout << s << '\n';
}
