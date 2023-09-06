#include <iostream>

using namespace std;

#define endl '\n'

int main()
{
	int hi, mi, hf, mf;
	cin >> hi >> mi >> hf >> mf;

	int dif =
		+ ((hf * 60) + mf)  // final minutes
		- ((hi * 60) + mi); // initial minutes

	if (dif <= 0) // if passed a day
		dif += 24 * 60;

	cout << "O JOGO DUROU " << dif / 60
		 << " HORA(S) E " << dif % 60 << " MINUTO(S)\n";
}
