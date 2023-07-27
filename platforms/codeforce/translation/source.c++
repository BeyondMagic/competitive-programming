#include <iostream>
#include <algorithm>

using namespace std;

#define endl '\n'

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	reverse(begin(s2), end(s2));
	if (s1 == s2)
		puts("YES");
	else
		puts("NO");

}
