#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, n, d, s, c, g;
	
	cin >> t;
	
	for (int i = 0; i < t; i++)
	{
		
		cin >> n;
		g = 1000;
		
		while (n)
		{
			cin >> d >> s;

			c = 2 * d + s;
			g = min(g, c);
			n--;
		}
		
		g = (g - 1) / 2;
		cout << g << endl;
	}
}
