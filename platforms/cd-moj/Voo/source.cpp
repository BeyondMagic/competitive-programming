#include <iostream>

#define space ' '

using namespace std;

typedef struct Time {
	int h, m;
} Time;

typedef struct Flight {
	Time departure, arrival;
} Flight;

int main()
{
	Flight A, B;
	scanf("%d:%d %d:%d %d:%d %d:%d",
			&A.departure.h, &A.departure.m, &A.arrival.h, &A.arrival.m,
			&B.departure.h, &B.departure.m, &B.arrival.h, &B.arrival.m
		);
	int pA = A.departure.h * 60 + A.departure.m;
	int cB = A.arrival.h * 60 + A.arrival.m;
	int pB = B.departure.h * 60 + B.departure.m;
	int cA = B.arrival.h * 60 + B.arrival.m;

	auto mod = [](int x, int m) {
		x %= m;
		if (x < 0)
			x += m;
		return x;
	};

	int X = mod(cB - pA, 1440);
	int Y = mod(cA - pB, 1440);
	int sum = X + Y;

	if (sum >= 1440)
		sum -= 1440;

	int t = sum / 2;

	int diff = (X - t) / 60;
	if (diff > 12)
		diff -= 24;

	else if (diff <= -12)
		diff += 24;

	cout << t << space << diff << endl;
}
