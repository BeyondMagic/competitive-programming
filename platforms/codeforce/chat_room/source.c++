#include <iostream>

using namespace std;

#define endl '\n'
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define printA(a,L,R) FE(i,L,R) cout << a[i] << (i==R?'\n':' ')
#define printV(a) printA(a,0,a.size()-1)

int main()
{
	char c;
	bool h = false,
		 e = false,
		 l1 = false,
		 l2 = false;

	while (cin >> c)
	{
		if (not h and c == 'h')
			h = true;
		else if (h and c == 'e')
			e = true;
		else if (not l1 and e and c == 'l')
			l1 = true;
		else if (not l2 and l1 and c == 'l')
			l2 = true;
		else if (l2 and c == 'o')
			return puts("YES"), 0;
	}
	puts("NO");
}
